import random

print(random.randint(1,9)) #выдает рандом от 1 до 9

print(random.randrange(10)) #выдает рандом от 0 до 9, не включая 10


#Кости 2.0
#Допишите программу Кости, таким образом, чтобы можно было предварительно ставить ставку на сумму,
# и в конце программа сравнивая ставку и результат, выводила или "Не повезло, давайте попробуем еще раз...".
# Или "Ура!!! Вы просто мега удачник))"

# Кости
# Демонстрируем рандомную генерацию чисел

import random

userGuess = int(input("Please, guess number on 2 to 12 "))

# компьютер генерируем числа рандомно 1 - 6
a = random.randint(1, 6)
b = random.randrange(6) + 1

total = a + b

print("Первая кость:", a, "Вторая кость:", b, "В сумме:", total)

while userGuess != total:
    print("Sorry, you are not guess, try again")
    userGuess = int(input())

print("Congratulation, you are winner")


input("\n\nPress the enter key to exit.")


# Кости 3.0
# Демонстрируем рандомную генерацию чисел


import random

while True:
    
    ## Делаем ставку
    S = int(input('Введите вашу ставку - от 2 до 12: '))


    # генерируем числа рандомно 1 - 6
    a = random.randint(1, 6)
    b = random.randrange(6) + 1
    total = a + b
    print("Первая кость:", a, "Вторая кость:", b, "В сумме:", total)



    # Выводим результат
    if total == S:
             print ('Ура, вы просто БОЛЬШОЙ везунчик!!!')
             break
    else:
             print ('Пробуем еще раз...\n\n')
             continue

input("\n\nPress the enter key to exit...")
