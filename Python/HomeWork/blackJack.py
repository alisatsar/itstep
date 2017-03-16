import random
import pygame
pygame.init()

WIN_WIDTH = 800 #Ширина создаваемого окна
WIN_HEIGHT = 640 # Высота
DISPLAY = (WIN_WIDTH, WIN_HEIGHT) # Группируем ширину и высоту в одну переменную
BACKGROUND_COLOR = "#004400"

gameDisplay = pygame.display.set_mode((DISPLAY, BACKGROUND_COLOR))

print("Welcome to Black Jack!\n")

bankroll = int(input("Please, enter your deposit: "))  # Игрок вносит депозит

menuChoose = 1

mass = ['A', 2, 3, 4, 5, 6, 7, 8, 9, 10, 'J', 'Q', 'K']

massAfterShuffle = mass * 24
random.shuffle(massAfterShuffle)
print(massAfterShuffle)

def converCard(card):
    if (card == 'J' or card == 'Q' or card == 'K'):
        card = int(10)
    if (card == 'A'):
        card = 11
    return card

#раздача карт
def giveCard (massAfterShuffle):
    сard = massAfterShuffle[0]
    massAfterShuffle.pop(0)
    return сard

#подсчет карт
def countScore(cardForScore):
    Score = 0
    i = 0
    count = len(cardForScore)
    while i < count:
        cardForScore[i] = converCard(cardForScore[i])
        Score += cardForScore[i]
        i = i + 1
    return int(Score)

def forPrintList(сard):
    i = 0
    count = len(сard)
    forPrint = [0]
    while i < count:
        forPrint[i] = сard[i]
        i = i + 1
    return forPrint

while menuChoose == 1:
    bet = int(input("Please, enter your bet: "))  # Игрок делает ставку

    # Проверка рентабельносити ставки
    while bet > bankroll:
        print("Your bankroll: ", bankroll)
        bet = int(input("Sorry, your bet more bankroll. Please, enter your bet: "))  # Игрок делает ставку

    #Раздача карт
    card1 = giveCard(massAfterShuffle)
    cardPlayer = [card1]
    forPrintPlayer = forPrintList(cardPlayer)
    card2 = giveCard(massAfterShuffle)
    card3 = giveCard(massAfterShuffle)
    cardPlayer.append(card3)
    print("You have card: ")
    print(cardPlayer)
    forPrintPlayer.append(card3)
    cardDealer = [card2]
    print("Dealer have card: ", cardDealer)
    playerScore = countScore(cardPlayer)
    print("Your score is: ", playerScore)
    forPrintDealer = forPrintList(cardDealer)
    dealerScore = countScore(cardDealer)
    print("Dealer score is: ", dealerScore)

    playerChoose = 1
    dealerHave = 1

    while playerChoose != "S":
        playerChoose = input("Please, enter your move: 'S' - stand, 'H' - hit me\n")
        if playerChoose == 'H':
            cardHit = massAfterShuffle[0]
            massAfterShuffle.pop(0)
            cardPlayer.append(cardHit)
            forPrintPlayer.append(cardHit)
            print("You have card: ", forPrintPlayer)
            playerScore = countScore(cardPlayer)
            if (playerScore >= 22):
                print("Your score: ", playerScore, "Too much. You lose\n")
                dealerHave = 0
                bankroll -= bet
                break
            else:
                print("Your score: ", playerScore)
                dealerHave = 1
                continue

    while dealerHave == 1 and dealerScore < 17:
        card = massAfterShuffle[0]
        massAfterShuffle.pop(0)
        cardDealer.append(card)
        forPrintDealer.append(card)
        print("The dealer takes a card: ", forPrintDealer)
        dealerScore = countScore(cardDealer)
        print("Dealer score: ", dealerScore)

    #Подсчет ставок
    if dealerScore > 21:
        bankroll += bet
        print("You win! ", bet)
    elif dealerScore > playerScore and dealerScore <= 21:
        bankroll -= bet
        print("You lose! ", bet)
    elif dealerScore > playerScore:
        bankroll -= bet
        print("You lose! ", bet)
    elif dealerScore < playerScore:
        bankroll += bet
        print("You win! ", bet)
    elif dealerScore == playerScore:
        bankroll = bankroll

    # Продолжаем игру или нет
    print("Your bankroll: ", bankroll)
    menuChoose = int(input("If you want play, enter - 1. If you want exit game, enter - 0: "))
    if menuChoose == 1:
        continue
    elif menuChoose == 0:
        break


