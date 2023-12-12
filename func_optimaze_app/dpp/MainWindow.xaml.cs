using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.ComponentModel;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using IronPython.Hosting;
using Microsoft.Scripting.Hosting;
using System.IO;


namespace dpp
{

    /// <summary>
    /// Логика взаимодействия для MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        
        public MainWindow()
        {
            InitializeComponent();
            System.IO.File.Delete(@"C:\Users\anton\source\repos\dpp\bin\Debug\output.txt");
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            Close();
        }

        private void Image_MouseDown(object sender, MouseButtonEventArgs e)
        {
            DragMove();
        }


        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            

            if (ComboBox1.Text == "Функция Розенброка") 
            {
                using (Process myProcess = new Process())
                {
                    Process.Start(@"C:\Users\anton\OneDrive\Рабочий стол\учеба\1.py");
                }
                MessageBox.Show("Функция успешно оптимизирована!");
            }
            if (ComboBox1.Text == "Функция Растригина")
            {
                using (Process myProcess = new Process())
                {
                    Process.Start(@"C:\Users\anton\OneDrive\Рабочий стол\учеба\2.py");
                }
                MessageBox.Show("Функция успешно оптимизирована!");
            }
            if (ComboBox1.Text == "окружность")
            {
                using (Process myProcess = new Process())
                {
                    Process.Start(@"C:\Users\anton\OneDrive\Рабочий стол\учеба\3.py");
                }
                MessageBox.Show("Функция успешно оптимизирована!");
            }
            if(ComboBox1.Text =="")
            {
                MessageBox.Show("Пожалуйста, выбирите функцию","ошибка", MessageBoxButton.OK, MessageBoxImage.Error);
            }
           
           


        }

        private void Button_Click_2(object sender, RoutedEventArgs e)
        {
            try { 
                StreamReader sr = new StreamReader("C:\\Users\\anton\\source\\repos\\dpp\\bin\\Debug\\output.txt");
                string line = sr.ReadLine();
                string[] res = line.Split(')');
                string s1 = res[0].Remove(0, 1).Trim();
                string s2 = res[1].Remove(0, 1).Remove(res[1].Length - 2, 1).Trim();
                MessageBox.Show($"Значения переменных, при которых достигается минимальное значение функции: {s1})\nMинимальное значение функции:{s2}");
            }
            catch
            {
                MessageBox.Show("Прежде чем смотреть результат оптимизируйте функцию", "ошибка", MessageBoxButton.OK, MessageBoxImage.Error);
            }
            
        }
    }
}
