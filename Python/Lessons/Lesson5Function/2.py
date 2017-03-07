#2. Напишите функции конвертации градусов Цельсия и Фаренгейта.

def conver(degree, whatIsDegree):
    if (whatIsDegree == 'F'):
        print(degree, "Fahrenheit = ")
        fahrenheit = degree * 32
        return fahrenheit
    if (whatIsDegree == 'C'):
        print(degree, "Celsius = ")
        celsius = degree / 32
        return celsius

degree = int(input("Enter degree: "))
whatIsDegree = input("If your degree is Fahrenheit press F, if degree is Celsius press C ")
print(conver(degree, whatIsDegree), whatIsDegree)
