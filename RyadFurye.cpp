// РядФурье.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <vector>
#include <assert.h>

#undef min
#undef max

double T = 1;

inline double square(double x) { return x * x; }

struct Pair
{
    int     i{ 0 };
    double  a{ 0.0 };
};

typedef std::vector<Pair> PairVector;

double f(int n)
{
    if (n < 2)
        return 1.0;
    double a = 1.0;
    for (int s = 1; s <= n / 2; s++)
        a *= (2.0 * s - 1.0) / (2.0 * s);
    return a;
}

double g(int n)
{
    if (n < 2)
        return 1.0;
    double a = 1;
    for (int s = 1; s <= n / 2; s++)
        a *= (2.0 * s) / (2.0 * s + 1.0);
    return a;
}

double h(int i, int j)
{
    if (i + j == 0)
        return T * 0.5;
    if (abs(i - j) == 1)
        return T * ((i - j) / (2.0 * sqrt(4.0 * square(std::max(i, j)) - 1)));
    return 0;
}


double atn(int i, int j, int n)
{
    if (n == 0)
    {
        if (i == j)
            return 1;

        return 0;
    }

    double a;
    if (i != 0)
    {
        a = (T / 2) * (((i + 1) / sqrt((2 * i + 1) * (2 * i + 3))) * atn(i + 1, j, n - 1)
            + atn(i, j, n - 1) + i / (sqrt((2 * i - 1) * (2 * i + 1))) * atn(i - 1, j, n - 1));
    }
    else
    {
        a = (T / 2) * (((i + 1) / sqrt((2 * i + 1) * (2 * i + 3))) * atn(i + 1, j, n - 1)
            + atn(i, j, n - 1));
    }
    return a;
}

bool z(int i, int j, int k)
{
    if (((i + j + k) % 2 == 0) && (abs(j - k) <= i) && (i <= j + k))
        return true;
    return false;
}

double v(int i, int j, int k)
{
    if (!z(i, j, k))
        return 0;

    double a = sqrt(((2 * i + 1) * (2 * j + 1) * (2 * k + 1)) / T);
    return a * (f(i + j - k) * f(j + k - i) * f(k + i - j) * g(i + j + k));
}


double delt(int i, int k)
{
    int b = (i == std::max(k - 1, 0));
    double a;
    if (k > 0)
        a = h(k - 1, k);
    else
        a = h(0, 0);
    return a * b;
}

double polymultint(const PairVector& M, int k)
{
    double R = 0;
    int col = 0;
    for (int j = 0; j < M.size(); j++)
    {
        int i = M[j].i;
        if (i == k)
            R += M[j].a;
    }
    return R;
}


int polydegree(const PairVector& M)
{
    int deg = 0;
    for (int l = 0; l < M.size(); l++)
        if (M[l].i > deg)
            deg = M[l].i;
    return deg;
}

inline void v_expand_to(PairVector& v, int index)
{
    if (index >= (int)v.size())
        v.resize(index + 1);
}

void polyint(PairVector& M)
{
    int col = 0;
    PairVector R;
    for (int l = 0; l < M.size(); l++)
    {
        v_expand_to(R, col + 1);

        int i = M[l].i;
        if (i == 0)
        {
            R[col].i = 0;
            R[col].a = h(0, 0) * M[l].a;
            R[col + 1].i = 1;
            R[col + 1].a = h(1, 0) * M[l].a;
        }
        else
        {
            R[col].i = i - 1;
            R[col].a = h(i - 1, i) * M[l].a;
            R[col + 1].i = i + 1;
            R[col + 1].a = h(i + 1, i) * M[l].a;

        }
        col += 2;
    }
    M = R;
}


void polysimplify(PairVector& M)
{
    int deg = polydegree(M);

    PairVector X, R;
    v_expand_to(X, deg);
    X[deg].a = 0;

    for (int l = 0; l < (int)M.size(); ++l)
    {
        int i = M[l].i;
        v_expand_to(X, i);
        X[i].a += M[l].a;
    }

    int col = 0;
    for (int l = 0; l <= deg; ++l)
    {
        if (X[l].a != 0)
        {
            v_expand_to(R, col);
            R[col].i = l;
            R[col].a = X[l].a;
            ++col;
        }
    }
    M = R;
}


void polymult(PairVector& M, int j)
{
    int col = 0;
    PairVector R;
    for (int l = 0; l < (int)M.size(); l++)
    {
        int i = M[l].i;
        int s1 = abs(i - j);
        int s2 = i + j;
        for (int k = s1; k <= s2; k++)
        {
            double c = v(i, j, k);
            if (c != 0)
            {
                v_expand_to(R, col);
                R[col].i = k;
                R[col].a = c * M[l].a;
                col += 1;
            }
        }
    }
    polysimplify(R);
    M = R;
}



void polymultmonom(PairVector& M, int  n)
{
    int col = 0;
    PairVector R;
    for (int l = 0; l < (int)M.size(); l++)
    {
        int i = M[l].i;
        int s = std::max(0, i - n);
        for (int j = s; j <= i + n; ++j)
        {
            v_expand_to(R, col);
            R[col].i = j;
            R[col].a = atn(i, j, n) * M[l].a;
            col += 1;
        }
    }
    polysimplify(R);
    M = R;
}

int main()
{
    //ввод входных данных
    std::cout << "input k >= 2 - the number of degrees and i-values: ";
    int k;
    std::cin >> k;
    std::cout << "\ninput the i-values: \n";
    std::vector<int> I;
    for (int x = 0; x < k; x++)
    {
        int tmp;
        std::cin >> tmp;
        I.push_back(tmp);
    }
    std::cout << "\nInput in one line the values of the degrees - int numbers:\n";
    std::vector<int> n(k, 0);
    for (int x = 0; x < k; x++)
    {
        std::cin >> n[x];
    }
    //Начало работы функции
    PairVector M;
    M.push_back(Pair{ I[0], 1 });
    if (n[0] > 0)
        polymultmonom(M, n[0]);
    //Главный цикл
    for (int l = 2; l < k; l++)
    {
        polyint(M);
        if (n[l - 1] > 0)
            polymultmonom(M, n[l - 1]);
        polymult(M, I[l - 1]);
    }
    //Завершение
    polyint(M);
    if (n[k - 1] > 0)
        polymultmonom(M, n[k - 1]);
    double Ans = polymultint(M, I[k - 1]);

    printf("we get this number : %g\n", Ans);
}
