import pygame
import time
import random
from pygame.locals import *
pygame.font.init()

window = pygame.display.set_mode((843, 600))
pygame.display.set_caption("Black Jack")

class Fon:
    def __init__(self, xpos, ypos, filename):
        self.x = xpos
        self.y = ypos
        self.bitmap = pygame.image.load(filename)

    def render(self):
        window.blit(self.bitmap, (self.x, self.y))

table = Fon(0,0,"table_blackjack.png")

done = True
while done == True:
    for e in pygame.event.get():
        if e.type == pygame.QUIT:
            done = False

    table.render()

    window.blit(window, (0, 0))  # отображаем игровой экран скрин
    pygame.display.flip()  # показать игровое окно

import random

#заполняем калоду карт, которая является двухмерным массивом вида [карта, масть, значение]
cards = []
i = 0
cardSuit = "s"
card = 1

while i < 52:
    if i == 13:
        cardSuit = "h"
        card = 1
    elif i == 26:
        cardSuit = "c"
        card = 1
    elif i == 39:
        cardSuit = "d"
        card = 1
    if card == 1:
        cards.append(["A", cardSuit, [1, 11]])
    elif card == 10:
        cards.append (["T", cardSuit, card])
    elif card == 11:
        cards.append(["J", cardSuit, 10])
    elif card == 12:
        cards.append(["Q", cardSuit, 10])
    elif card == 13:
        cards.append(["K", cardSuit, 10])
    else:
        cards.append([card, cardSuit, card])
    card += 1
    i += 1

cardsAfterShuffle = cards * 6
random.shuffle(cardsAfterShuffle)
print(cardsAfterShuffle)
