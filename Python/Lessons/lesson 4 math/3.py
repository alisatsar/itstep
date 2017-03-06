#3.Дано положительное действительное число X. Выведите его дробную часть. Сделайте два вывода.

import math

userNumber = float(input("Enter the float number: "))

fractionalPart = userNumber - int(userNumber)

counterNumber = len(str(userNumber))
counterNumberInt = len(str(int(userNumber)))
fractionalPart = round(fractionalPart, int(counterNumber))

finalNumber = fractionalPart * (10 ** (counterNumber -  counterNumberInt - 1))
print(int(finalNumber))


#4. Дано положительное действительное число X. Выведите его первую цифру после десятичной точки.

userNumber = float(input("Please, enter your float number\n"))

fractionalPart = userNumber - int(userNumber)

finalNumber = fractionalPart * 10
print(int(finalNumber))
