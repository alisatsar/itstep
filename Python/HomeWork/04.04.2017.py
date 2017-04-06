"""Напишите программу, запрашивающую у пользователя ввод числа. Если число принадлежит диапазону от -100 до 100,
то создается объект одного класса, во всех остальных случаях создается объект другого класса.
В обоих классах должен быть метод-конструктор __init__, который в первом классе возводит число в квадрат,
а во-втором - умножает на два."""

class UnRange:
    def __init__ (self, number):
        self.result = number * 2
        print(self.result)

class InRange:
    def __init__ (self, number):
        self.result = number ** 2
        print(self.result)

userNumber = int(input("Enter your number: "))
if userNumber >= -100 and userNumber <= 100:
    userNumber = InRange(userNumber)

else:
    userNumber = UnRange(userNumber)
    



#Напишите программу, высчитывающую площадь оклейки обоями комнаты. Объектами являются: стены, потолки, окна и двери.

class Wallpaper:
    def __init__(self, width, height, length):
        self.width = width
        self.height = height
        self.length = length
        self.square = 2 * self.height * (self.width + self.length)
        return s
        


width = int(input("Enter the width of wall your room: "))
height = int(input("Enter the height of wall your room: "))
length = int(input("Enter the length of your room: "))

wallpaper = Wallpaper(width, height, length)
squareWithoutDoorsAndWindows = 
