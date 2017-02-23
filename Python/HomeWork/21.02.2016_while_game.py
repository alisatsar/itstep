#Игра кости

#добавляем рандом
import random

print("Welcome to casino!\n")

# Предложение выбора режима игры
chooseOpponent = input("Please, choose opponent: D - play with dealer, C - computer, A - another player: \n")

# Играет один с диллером
if chooseOpponent == 'D' or 'd':
    bankroll = int(input("Please, enter your deposit: "))  # Игрок вносит депозит
    menuChoose = 1

    while menuChoose == 1:
        if bankroll == 0:
            addDeposit = int(input("You want to replenish your Deposit? 1 - Yes, 2 - No"))
            if addDeposit == 1:
                bankroll = int(input("Please, enter your deposit: "))  # Игрок вносит депозит
            else:
                break

        bet = int(input("Please, enter your bet: "))  # Игрок делает ставку
        # Проверка рентабельносити ставки
        while bet > bankroll:
            print("Your bankroll: ", bankroll)
            bet = int(input("Sorry, your bet more bankroll. Please, enter your bet: "))  # Игрок делает ставку

        guessNumber = int(input("Please, enter number from 2 to 12: "))  # Игрок загадывает число

        # Проверка введеннох данных игроком
        while guessNumber < 1 or guessNumber > 13:
            guessNumber = int(input("Your number is not correct. Please, enter number from 2 to 12: "))

        # Диллер делает бросок
        print("The dealer makes the throw: ")
        dise1 = random.randint(1, 6)  # кость 1
        dise2 = random.randint(1, 6)  # кость 2

        totalScore = dise1 + dise2  # общий счет
        # если угадал
        if totalScore == guessNumber:
            bankroll = bet * 2 + bankroll  # подсчет банкрола если угадал
            print("Dise №1 ", dise1, "\nDise №2 ", dise2, "\nDealer total score: ", totalScore,
                  "\nCongratulation! You are winner!\nYour bankroll = ", bankroll)
        # если угадал
        else:
            bankroll = bankroll - bet  # подсчет банкрола если не угадал
            print("Dise №1 ", dise1, "\nDise №2 ", dise2, "\nDealer total score: ", totalScore,
                  "\nYou are not guess!\nYour bankroll = ", bankroll)

        #Продолжаем игру или нет
        menuChoose = int(input("If you want play, enter - 1. If you want exit game, enter - 0: "))
        if menuChoose == 1:
            continue
        elif menuChoose == 0:
            break

#Играет с компьютером
if chooseOpponent == 'C' or 'c':
    deposit = int(input("Please, enter your deposit: "))  # Игрок вносит депозит
    bankroll = deposit
    menuChoose = 1
    bankrollComputer = deposit  # компьютеру устанавливается такой же депозит как и пользователю

    while menuChoose == 1:
        if bankroll == 0:
            addDeposit = int(input("You want to replenish your Deposit? 1 - Yes, 2 - No: "))
            if addDeposit == 1:
                bankroll = int(input("Please, enter your deposit: "))  # Игрок вносит депозит
            else:
                break

        if bankrollComputer == 0:
            addDeposit = int(input("You want to replenish your Deposit? 1 - Yes, 2 - No: "))
            if addDeposit == 1:
                bankrollComputer = int(input("Please, enter your deposit: "))  # Игрок вносит депозит
            else:
                break

        betUser = int(input("Please, enter your bet: "))  # Пользователь делает ставку
        # Проверка рентабельносити ставки
        while betUser > bankroll:
            print("Your bankroll: ", bankroll)
            betUser = int(input("Sorry, your bet more bankroll. Please, enter your bet: "))  # Игрок делает ставку

        betComputer = random.randint(1, bankrollComputer)  # Компютер делает ставку

        guessNumberUser = int(input("Please, enter number from 2 to 12: "))  # Пользователь загадывает число
        print("Computer deposit: ", bankrollComputer)

        # Проверка введеннох данных пользователем
        while guessNumberUser < 1 or guessNumberUser > 13:
            guessNumberUser = int(input("Your number is not correct. Please, enter number from 2 to 12: "))

        guessComputerNumber = random.randint(1, 6) + random.randint(1, 6)  # Компьютер загадывает число
        print("Computer bet: ", betComputer, "Computer number: ", guessComputerNumber)

        # Диллер делает бросок
        print("The dealer makes the throw: ")
        dise1 = random.randint(1, 6)  # кость 1
        dise2 = random.randint(1, 6)  # кость 2

        totalScore = dise1 + dise2  # общий счет

        # Если компьютер или пользователь угадал или не угадал
        if guessNumberUser == totalScore or guessComputerNumber == totalScore:
            print("Dise №1 ", dise1, "\nDise №2 ", dise2, "\nDealer total score: ", totalScore)
            if guessNumberUser == totalScore and guessComputerNumber != totalScore:
                bankroll = bankroll + betUser * 2
                bankrollComputer = bankroll - betComputer
                print("You winner, but computer no!\nYour bankroll = ", bankroll,
                          "Computer bankroll = ", bankrollComputer)
            if guessNumberUser != totalScore and guessComputerNumber == totalScore:
                bankroll = bankroll - betUser
                bankrollComputer = bankrollComputer + betComputer * 2
                print("Computer winner, but you no!\nYour bankroll = ", bankroll,
                          "Computer bankroll = ", bankrollComputer)

        # Если угадали оба
        elif guessNumberUser == totalScore and guessComputerNumber == totalScore:
            bankroll = bankroll + betUser * 2
            bankrollComputer = bankrollComputer + betComputer * 2
            print("Dise №1 ", dise1, "\nDise №2 ", dise2, "\nDealer total score: ", totalScore)
            print("Computer and you winner!\nYour bankroll = ", bankroll,
                      "Computer bankroll = ", bankrollComputer)

        # Если оба не угадали
        elif guessNumberUser != totalScore or guessComputerNumber != totalScore:
            print("Dise №1 ", dise1, "\nDise №2 ", dise2, "\nDealer total score: ", totalScore)
            bankroll = bankroll - betUser
            bankrollComputer = bankrollComputer - betComputer
            print("Computer and you not guess!\nYour bankroll = ", bankroll,
                      "Computer bankroll = ", bankrollComputer)

        # Продолжаем игру или нет
        menuChoose = int(input("If you want play, enter - 1. If you want exit game, enter - 0: "))
        if menuChoose == 1:
            continue
        elif menuChoose == 0:
            break

#Игрок играет с другим игроком
if chooseOpponent == 'A' or 'a':
    menuChoose = 1

    namePlayer1 = input("What is your name player 1: ")
    namePlayer2 = input("What is your name player 2: ")

    depositPlayer1 = int(input("%s, please enter your deposit: " %namePlayer1)) # Игрок №1 вносит депозит
    depositPlayer2 = int(input("%s, please enter your deposit: " %namePlayer2))  # Игрок №2 вносит депозит

    while menuChoose == 1:
        if depositPlayer1 == 0:
            addDeposit = int(input("%s, you want to replenish your Deposit? 1 - Yes, 2 - No" %namePlayer1))
            if addDeposit == 1:
                depositPlayer1 = int(input("Please, enter your deposit: "))  # Игрок вносит депозит
            else:
                break

        if depositPlayer2 == 0:
            addDeposit = int(input("%s, you want to replenish your Deposit? 1 - Yes, 2 - No" %namePlayer2))
            if addDeposit == 1:
                depositPlayer2 = int(input("Please, enter your deposit: "))  # Игрок вносит депозит
            else:
                break

        betPlayer1 = int(input("%s, please enter your bet: " %namePlayer1))  #Игрок №1 делает ставку делает ставку
        while betPlayer1 > depositPlayer1:
            print(namePlayer1, ", your bankroll: ", depositPlayer1)
            betPlayer1 = int(input("Sorry, your bet more bankroll. Please, enter your bet: "))

        betPlayer2 = int(input("%s, please enter your bet: " %namePlayer2))  # Игрок №2 делает ставку делает ставку
        while betPlayer2 > depositPlayer2:
            print(namePlayer2, ", your bankroll: ", depositPlayer2)
            betPlayer2 = int(input("Sorry, your bet more bankroll. Please, enter your bet: "))

        guessPlayer1 = int(input("%s, please enter number from 2 to 12: " %namePlayer1))  #Игрок №1 загадывает число

        # Проверка введенных данных игроком №1
        while guessPlayer1 < 1 or guessPlayer1 > 13:
            guessPlayer1 = int(input("Your number is not correct. Please, enter number from 2 to 12: "))

        guessPlayer2 = int(input("%s, please enter number from 2 to 12: " %namePlayer2))  # Игрок №2 загадывает число

        # Проверка введенных данных игроком №2
        while guessPlayer2 < 1 or guessPlayer2 > 13:
            guessPlayer2 = int(input("Your number is not correct. Please, enter number from 2 to 12: "))

        # Диллер делает бросок
        print("The dealer makes the throw: ")
        dise1 = random.randint(1, 6)  # кость 1
        dise2 = random.randint(1, 6)  # кость 2

        totalScore = dise1 + dise2  # общий счет

        # Если угадал игрок №1 или игрок №2
        if guessPlayer1 == totalScore or guessPlayer2 == totalScore:
            print("Dise №1 ", dise1, "\nDise №2 ", dise2, "\nDealer total score: ", totalScore)
            if guessPlayer1 == totalScore and guessPlayer2 != totalScore:
                depositPlayer1 = (depositPlayer1 - betPlayer1) + betPlayer1 * 2
                depositPlayer2 = depositPlayer2 - betPlayer2
                print(namePlayer1, " winner, but", namePlayer2, " no!\n", namePlayer1, " bankroll = ", depositPlayer1,
                      namePlayer2, " bankroll = ", depositPlayer2)
            if guessPlayer1 != totalScore and guessPlayer2 == totalScore:
                depositPlayer1 = depositPlayer1 - betPlayer1
                depositPlayer2 = (depositPlayer2 - betPlayer2) + betPlayer2 * 2
                print(namePlayer2, " winner, but", namePlayer1, " no!\n", namePlayer1, " bankroll = ", depositPlayer1,
                      namePlayer2, " bankroll = ", depositPlayer2)
        # Если угадали оба
        elif guessPlayer1 == totalScore and guessPlayer1 == totalScore:
            depositPlayer1 = (depositPlayer1 - betPlayer1) + betPlayer1 * 2
            depositPlayer2 = (depositPlayer2 - betPlayer2) + betPlayer2 * 2
            print("Dise №1 ", dise1, "\nDise №2 ", dise2, "\nDealer total score: ", totalScore)
            print(namePlayer1, " and ", namePlayer2, " winners!\n", namePlayer1, " bankroll = ", depositPlayer1,
                  namePlayer2, " bankroll = ", depositPlayer2)

        # Если оба не угадали
        elif guessPlayer1 != totalScore or guessPlayer1 != totalScore:
            print("Dise №1 ", dise1, "\nDise №2 ", dise2, "\nDealer total score: ", totalScore)
            depositPlayer1 = depositPlayer1 - betPlayer1
            depositPlayer2 = depositPlayer2 - betPlayer2
            print(namePlayer1, " and ", namePlayer2, " not guess!\n", namePlayer1, " bankroll = ", depositPlayer1,
                  namePlayer2, " bankroll = ", depositPlayer2)

        # Продолжаем игру или нет
        menuChoose = int(input("If you want play, enter - 1. If you want exit game, enter - 0: "))
        if menuChoose == 1:
            continue
        elif menuChoose == 0:
            break

input("Press enter for continue...")
