import random

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

#раздача карт игроку
def giveCardPlayer (massAfterShuffle):
    playerCard1 = massAfterShuffle[0]
    massAfterShuffle.pop(0)
    playerCard2 = massAfterShuffle[1]
    massAfterShuffle.pop(1)
    print("You have card: ", playerCard1, playerCard2)
    сardPlayer = [playerCard1, playerCard2]
    return сardPlayer

#раздача карт дилеру
def giveCardDealer (massAfterShuffle):
    dealerCard1 = massAfterShuffle[0]
    massAfterShuffle.pop(0)
    print("Dealer have card: ", dealerCard1)
    cardDealer = [dealerCard1]
    return cardDealer

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

    сardPlayer = giveCardPlayer(massAfterShuffle)
    forPrintPlayer = forPrintList(сardPlayer)
    playerScore = countScore(сardPlayer)
    print(playerScore)
    cardDealer = giveCardDealer (massAfterShuffle)
    forPrintDealer = cardDealer
    dealerScore = countScore(cardDealer)

    playerChoose = 1
    dealerHave = 1

    while playerChoose != "S":
        playerChoose = input("Please, enter your move: 'S' - stand, 'H' - hit me\n")
        if playerChoose == 'H':
            cardHit = massAfterShuffle[0]
            massAfterShuffle.pop(0)
            сardPlayer.append(cardHit)
            forPrintPlayer.append(cardHit)
            print("You have card: ", forPrintPlayer)
            playerScore = countScore(сardPlayer)
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

    if dealerScore > 21:
        bankroll += bet
    elif dealerScore > playerScore and dealerScore <= 21:
        bankroll -= bet
    elif dealerScore > playerScore:
        bankroll -= bet
    elif dealerScore == playerScore:
        bankroll = bankroll

    # Продолжаем игру или нет
    print("Your bankroll: ", bankroll)
    menuChoose = int(input("If you want play, enter - 1. If you want exit game, enter - 0: "))
    if menuChoose == 1:
        continue
    elif menuChoose == 0:
        break
