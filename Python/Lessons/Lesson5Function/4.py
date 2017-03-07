#4. Дано действительное положительное число a и целоe число n.
# Вычислите an. Решение оформите в виде функции power(a, n).
# Стандартной функцией возведения в степень пользоваться нельзя.

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
