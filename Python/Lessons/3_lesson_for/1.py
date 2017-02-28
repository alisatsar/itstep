1. Даны два целых числа A и B (при этом A ≤ B). Выведите все числа от A до B включительно.

A = int(input("Press number A: ")) #Ввод чисел
B = int(input("Press number B: "))
#Проверка на то, чтобы А < B
while B < A:
    B = int(input("The number B Must be more than A"))
#Вывод чисел включительно
for i in range(A, B + 1):
    print(i, end = " ")

input("\nPress enter to continue...")
