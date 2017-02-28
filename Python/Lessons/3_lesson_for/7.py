#7. Факториалом числа n называется произведение 1 × 2 × ... × n. Обозначение: n!.
# По данному натуральному n вычислите значение n!.

number = int(input("Please enter the number which factorial you want to calculate: "))

factorial = 1

for i in range(number):
    i = i + 1
    factorial *= i

print("\nThe factorial of number", number, " = ", factorial)

input("\nPress enter to continue...")
