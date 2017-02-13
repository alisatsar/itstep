#4.Вычислить площадь круга S=pi*r*r, pi описать как константу, значение переменной r ввести с клавиатуры.

import math
pi = math.pi #значение числа pi

r = int(input("Enter r\n")) #Пользователь вводит с клавиатуры радиус


print("S =",pi * r * r)
input("Press Enter for continue...\n")