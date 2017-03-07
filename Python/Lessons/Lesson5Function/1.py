#1. Напишите функции уравнений:
#x в степени 4 + 4 в степени x,
#y в степени 4  + 4 в степени x.

def calculate(a):
    result = (a ** 4) + (4 ** a)
    return result

x = int(input("Enter your number x: "))
y = int(input("Enter your number y: "))
print("(x ** 4) + (4 ** x) = ", calculate(x))
print("(y ** 4) + (4 ** y) = ", calculate(y))
