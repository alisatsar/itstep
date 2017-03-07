#3. Даны четыре действительных числа: x1, y1, x2, y2. Напишите функцию distance(x1, y1, x2, y2),
#вычисляющая расстояние между точкой (x1,y1) и (x2,y2). Считайте четыре действительных числа
#и выведите результат работы этой функции. Используйте теорему Пифагора.

import math

def distance(x1, y1, x2, y2):
    x = abs(x1 - x2)
    y = abs(y1 - y2)
    print(x, y)
    result = math.sqrt((x ** 2) + (y ** 2))
    return result

x1 = float(input("Enter the coordinate of x for point 1: "))
y1 = float(input("Enter the coordinate of y for point 1: "))
x2 = float(input("Enter the coordinate of x for point 1: "))
y2 = float(input("Enter the coordinate of y for point 1: "))
print("The length of the segment (x1, y1) (x2, y2) = ", round(distance(x1, y1, x2, y2), 2))
