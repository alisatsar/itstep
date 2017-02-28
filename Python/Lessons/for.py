for <target>  in <object>:    # Связывает элементы объекта с переменной цикла
    <statements>        # Повторяющееся тело цикла: использует переменную цикла
else:
    <statements>        # Если не попали на инструкцию ‘break’
for <target>  in <object>:  # Присваивает элементы объекта с переменной цикла
     <statements>
    if <test>: break       # Выход из цикла, минуя блок else
    if <test>: continue    # Переход в начало цикла
else:
     <statements>           # Если не была вызвана инструкция ‘break’


for x in ["e", "b", "c"]:
    print(x, end = " ")     #присвоим переменной x каждый из трех элементов списка 
    
sum = 0
b = 3
for x in [1, 2, 3, 4]:
    sum = sum + x
    b = b * x
    print(sum, end = " ")
    print(b, end = " ")
    
S = "lumberjack"
T = ("and", "I’m", "okay")
for x in S:
    print(x, end=" ")       # Обход строки
for x in T:
    print(x, end=" ")       # Обход элементов кортежа
    
T = [(1, 2), (3, 4), (5, 6)]
for (a, b) in T:             # Операция присваивания кортежа в действии
    print(a, b)

    
print("Counting")
for i in range(10):
    print(i, end= " ")

print("\n\ncounting by fives")
for i in range(0, 51, 5): #считает от 0 до 50 с шагом 5
    print(i, end= ' ')

print("\n\nCounting backwards")
for i in range(10, 0, -1):
    print(i, end=" ")

i = 1
for color in "red", "orange", "yellow", 'green', 'cyan', 'blue', 'violet':
    print("#", i, color, sep = ' ') #sep = ' ' между каждыми элементами в принте ставит разделитель
    i += 1

for i in 1, 2, 3, 'one', 'two', 'three':
    print(i, ",", sep = '')

for i in range(4):
    print(i)
    print(i ** 2)
print("finish")

sum = 0
n = 10
for i in range(n, -1, -2):
    sum += i
print(sum)

messege = input("Enter messege: ")
newMessege = ''
VOWELS = 'aeiauy'

print()
for letter in messege:
    if letter.lower() not in VOWELS:
        newMessege += letter
        print("A new string has been created: ", newMessege)

print("\nYour messege")
