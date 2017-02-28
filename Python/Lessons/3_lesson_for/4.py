"""4. Дано 10 целых чисел. Вычислите их сумму. Напишите программу, использующую наименьшее число переменных."""

import random

sum = 0
print("Random numbers: ")
#Забиваем рандомные числа от 0 до 10, выводим их на экран
for i in range(10):
    i = random.randint(0,10)
    print(i, end = " ")
    sum += i    #Сумммируем рандомные числа

print("\nSum of numbers = ", sum)

input("\nPress enter to continue...")
