#6. По данному натуральном n вычислите сумму 13+23+33+...+n3.

counterNumbers = int(input("Please enter the number of integers you wish to calculate in degree: "))

sum = 0

#Забиваем рандомные числа от 0 до 10, выводим их на экран
for i in range(counterNumbers):
    i = i + 1
    sum += i ** 3
    print(i, "** 3 =", i ** 3)#Сумммируем рандомные числа

print("\nSum of numbers in degree 3 = ", sum)

input("\nPress enter to continue...")
