userNumber = int(input("Please, enter your number on 100000 to 999999\n"))

even = 0
notEven = 0
countEven = 0
countNotEven = 0

b = 100000
a = 1000000

while b > 0:
    number1 = int(userNumber % a / b)
    if number1 % 2:
        even = even + number1
        countEven += 1
    else:
        notEven = notEven + number1
        countNotEven += 1
    b = b // 10
    a = a // 10
    print(number1)
print(even, notEven)
print(countEven, countNotEven)

input("Please press enter for continue...")