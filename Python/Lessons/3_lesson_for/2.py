#2. Даны два целых числа A и В. Выведите все числа от A до B включительно,
# в порядке возрастания, если A < B, или в порядке убывания в противном случае.

A = int(input("Press number A: ")) #Ввод чисел
B = int(input("Press number B: "))
if A > B:
    buff = B
    B = A
    A = buff
#Вывод чисел включительно
for i in range(A, B + 1):
    print(i)

input("\nPress enter to continue...")
