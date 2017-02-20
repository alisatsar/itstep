#1.Более сложный вариант!
#Допишите программу Кости таким образом, чтобы можно было играть с компьютером  или с другим игроком в кости, при этом
# в начале игры был выбор с кем играть - компьютер или партнер.

import random

chooseOpponent = input("Please, choose opponent: C - computer, A - another player \n")

if chooseOpponent == 'C':
    counterComputerThrow = 0
    counterPlayerThrow = 0
    totalScoreComputer = 0
    totalScorePlayer = 0
    throw = 0

    while throw <= 4:
        counterComputerThrow = counterComputerThrow + 1
        print("The computer makes the ", counterComputerThrow,  "throw: ")
        computerThrow1 = random.randint(1, 6)
        computerThrow2 = random.randint(1, 6)
        totalComputer = computerThrow1 + computerThrow2
        print("Throw",  counterComputerThrow, ": \ndice 1 = ", computerThrow1, "\ndice 2 = ",
              computerThrow2, "\nTotal = ", totalComputer)
        totalScoreComputer = totalScoreComputer + totalComputer

        counterPlayerThrow = counterPlayerThrow + 1
        print("The player makes the ", counterPlayerThrow, "throw: ")
        playerThrow1 = random.randint(1, 6)
        playerThrow2 = random.randint(1, 6)
        totalPlayer = playerThrow1 + playerThrow1
        print("Throw", counterPlayerThrow, ": \ndice 1 = ", playerThrow1, "\ndice 2 = ",
              playerThrow2, "\nTotal = ", totalPlayer)
        totalScorePlayer = totalScorePlayer + totalPlayer
        throw = counterComputerThrow + counterPlayerThrow


    if totalScorePlayer < totalScoreComputer:
        print("\nYour score: ", totalScorePlayer,"\nComputer score: ", totalScoreComputer, "\nComputer winner!!!")
    elif totalScorePlayer > totalScoreComputer:
        print("\nYour score: ", totalScorePlayer,"\nComputer score: ", totalScoreComputer, "\nYou are winner!!!")
    elif totalScorePlayer == totalScoreComputer:
        print("\nYour score: ", totalScorePlayer,"\nComputer score: ", totalScoreComputer, "\nWinner both!!!")

if chooseOpponent == 'A':
    counterPlayer1Throw = 0
    counterPlayer2Throw = 0
    totalScorePlayer1 = 0
    totalScorePlayer2 = 0
    throw = 0

    while throw <= 4:
        counterPlayer1Throw = counterPlayer1Throw + 1
        print("The computer makes the ", counterPlayer1Throw,  "throw: ")
        player1Throw1 = random.randint(1, 6)
        player1Throw2 = random.randint(1, 6)
        totalPlayer1 = player1Throw1 + player1Throw2
        print("Throw",  counterPlayer1Throw, ": \ndice 1 = ", player1Throw1, "\ndice 2 = ",
              player1Throw1, "\nTotal = ", totalPlayer1)
        totalScorePlayer1 = totalScorePlayer1 + totalPlayer1

        counterPlayer2Throw = counterPlayer2Throw + 1
        print("The computer makes the ", counterPlayer2Throw, "throw: ")
        player2Throw1 = random.randint(1, 6)
        player2Throw2 = random.randint(1, 6)
        totalPlayer2 = player2Throw1 + player2Throw2
        print("Throw", counterPlayer2Throw, ": \ndice 1 = ", player2Throw1, "\ndice 2 = ",
              player2Throw1, "\nTotal = ", totalPlayer2)
        totalScorePlayer2 = totalScorePlayer2 + totalPlayer2
        throw = totalScorePlayer1 + totalScorePlayer2


    if totalScorePlayer1 < totalScorePlayer2:
        print("\nPlayer 1 score: ", totalScorePlayer1,"\nPlayer 2 score: ", totalScorePlayer2, "\nPlayer 2 winner!!!")
    elif totalScorePlayer1 > totalScorePlayer2:
        print("\nPlayer 1 score: ", totalScorePlayer1, "\nPlayer 2 score: ", totalScorePlayer2, "\nPlayer 1 winner!!!")
    elif totalScorePlayer == totalScoreComputer:
        print("\nPlayer 1 score: ", totalScorePlayer1, "\nPlayer 2 score: ", totalScorePlayer2, "\nWinner both!!!")
