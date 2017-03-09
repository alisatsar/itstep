import random

mass = [ 'A', 2, 3, 4, 5, 6, 8, 9, 10, 'J', 'Q', 'K' ]

mass2 = mass * 24
random.shuffle(mass2)
print(mass2)

card = 0
i = 0
j = 0
end = 156
summGamer = 0
answerGamer = "S"

while i < 156:
    #Первая раздача
    if mass == 'J' or mass[i] == 'Q' or mass[i] == 'K':
        mass = int(10)
    while answerGamer == 'S':
        cardG1 = mass[i]
        cardG2 = mass[i + 2]
        cardD1 = mass[i + 1]
        j = 3
        totalGamer = cardG1 + cardG2
        print("\n",totalGamer)
        answerGamer = input("\nYou want more card")
    i = i + j
