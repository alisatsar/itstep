import random

print("Welcome to Black Jack!\n")

bankroll = int(input("Please, enter your deposit: "))  # Игрок вносит депозит

menuChoose = 1

mass = ['A', 2, 3, 4, 5, 6, 7, 8, 9, 10, 'J', 'Q', 'K']

mass2 = mass * 24
random.shuffle(mass2)
#print(mass2)

def converCard(card):
    if (card == 'J' or card == 'Q' or card == 'K'):
        card = int(10)
        return card
    if (card == 'A'):
        card = {"value": [1, 11]}
        return card

#раздача карт
def giveCard (mass2):
    playerCard1 = mass2[0]
    mass2.pop(0)
    dealerCard1 = mass2[0]
    mass2.pop(0)
    playerCard2 = mass2[0]
    mass2.pop(0)
    print("You have card: ", playerCard1, playerCard2)
    print("Dealer have card: ", dealerCard1)
    return playerCard1, dealerCard1, playerCard2

#подсчет карт
def countScore(t):
    playerCard1 = t(0)
    playerCard1 = converCard(playerCard1)
    playerCard2 = t(2)
    playerCard2 = converCard(playerCard2)
    dealerCard1 = t(1)
    dealerCard1 = converCard(dealerCard1)
    playerScore = playerCard1 + playerCard2
    dealerScore = dealerCard1
    return playerScore, dealerScore

while menuChoose == 1:
    bet = int(input("Please, enter your bet: "))  # Игрок делает ставку

    # Проверка рентабельносити ставки
    while bet > bankroll:
        print("Your bankroll: ", bankroll)
        bet = int(input("Sorry, your bet more bankroll. Please, enter your bet: "))  # Игрок делает ставку

    t = giveCard(mass2)
    countScore(t)
    playerScore = int(t[0])
    dealerScore = t[1]

    print(playerScore)
    print(dealerScore)

    playerChoose = 1
    dealerHave = 1

    while playerChoose != "S":
        playerChoose = input("Please, enter your move: 'S' - stand, 'H' - hit me\n")
        if playerChoose == 'H':
            cardHit = mass2[0]
            mass2.pop(0)
            print("You have card: ", cardHit)
            cardHit = converCard(cardHit)
            playerScore = int(playerScore + cardHit)
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
        cardDealer = mass2[0]
        print("The dealer takes a card: ", cardDealer)
        mass2.pop(0)
        cardDealer = int(converCard(cardDealer))
        dealerScore = dealerScore + cardDealer
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
