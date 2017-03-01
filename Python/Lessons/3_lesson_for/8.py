#8. По данному натуральном n вычислите сумму 1!+2!+3!+...+n!.
# В решении этой задачи можно использовать только один цикл.

userNumber = int(input("Please, enter the number to calculate the sum of factorials: "))
sum = 0
factorial = 1

for i in range(userNumber):
    i += 1
    factorial *= i
    print("!", i, " = ", factorial)
    sum += factorial

print("The sum of factorials: ",sum)
