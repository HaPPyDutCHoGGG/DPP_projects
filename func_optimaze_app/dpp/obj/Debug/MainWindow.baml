   M S B A M L   `   `   `  ����>  :dpp, Version=1.0.0.0, Culture=neutral, PublicKeyToken=nullclr-namespace:dppdpp  5   	       dpp.MainWindow   5   	   R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35\ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5   	   R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   @d2http://schemas.microsoft.com/expression/blend/2008     5   	   Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5   	   #localclr-namespace:dpp     5   	   _ [MaterialDesignThemes.Wpf, Version=4.9.0.0, Culture=neutral, PublicKeyToken=df2a72020bd7962aFmaterialDesign1http://materialdesigninxaml.net/winfx/xaml/themes  5   	   U QWpfAnimatedGif, Version=2.0.0.0, Culture=neutral, PublicKeyToken=9e7cd3b544a090dc,gif"http://wpfanimatedgif.codeplex.com  5   	     � Title$  
MainWindow��5
      $	��700��6    $	��965��6-    � WindowStyle$
 None=�69   .��5      � 
����İ�.+�5   
   �� -   5        $7��1C:\Users\anton\source\repos\dpp\Resources\fon.jpg��5      $��0,0,0,3q�6K   6z   �� 5   
   $	��400��6   $	��400��6    $��	15,0,15,0q�6-   
�������$��Center=�6S    �� Padding$ 30q�6n   $	��550��6{    �� CornerRadius$ 20��6�    J� Effect 5      3  -System.Windows.Media.Effects.DropShadowEffect  5         
BlurRadius$ 30Q�6#      Color$
 Gray��63      ShadowDepth$ 0Q�6@   ._�5      �� .+�5      � $��0 0 0 20q�6   $	��494��6)    J� RenderTransformOrigin$ 0.117,0.531&�65   $��70��6Y   .+�5      �� -   5        $��10,10,418,16q�5      $ 0.5,0.5&�6H   ��5      �� 5      	 �� 
TargetType"	 ��6/   .R�5   "   � .+�5   &   A� 
�������6=   �� 5   &   $?��9C:\Users\anton\source\repos\dpp\Resources\nowatermark.png��6-   6r   5   #   5      5      5      � 5      $��0 0 0 0q�6   $	��201��6(   $ 0.117,0.531&�64   $��95��6X   .+�5       �� "  WpfAnimatedGif.ImageBehavior
   RepeatBehavior$
 Forever��6      AnimatedSource$G AC:\Users\anton\source\repos\dpp\Resources\cirkuliruyushiy-tor.gif��6G   $G��AC:\Users\anton\source\repos\dpp\Resources\cirkuliruyushiy-tor.gif��6�   $��
0,-29,0,29q�6�   6  5"      �� 5#      -   5         ��Name$ 	ComboBox1��5#      .@�5$      �� �� 6!   $)�#Функция Розенброка��6%   $
��Bold"�6?   6T   �� 5%      �� 6!   $)�#Функция Растригина��6%   $
��Bold"�6?   6T   �� 5&      �� 6!   $�окружность��6%   $
��Bold"�67   6L   5'      �� 5(      .��6   !Выберите функцию6,   �� 5)      -   5        $#��Оптимизировать!��5)      $��0 15 0 0q�63   6E   �� 5*      -   5        $/��)Просмотреть результат��5*      $��0 10 0 0q�69   6K   5+      5,      5-      5.      