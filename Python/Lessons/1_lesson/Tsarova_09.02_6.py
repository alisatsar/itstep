#6.Программа, которая считывает радиус круга и печатает диаметр круга, длину окружности и площадь.
# Используйте значение константы 3.14159 для числа Пи. Выполните эти вычисления в операторе вывода.

import math
pi = round(float(math.pi), 6)

r = float(input("Enter radius\n")) #Пользователь вводит с клавиатуры радиус

s = r * r * pi #Вычислить площадь
circumference = 2 * pi * r #Вычислить длину круга
diameter = 2 * r #Вычислить диаметр круга

print("The diameter of the circle: ", diameter)
print("the circumference: ", circumference)
print("The area of a circle: ", s)
input("Press Enter for continue...\n")