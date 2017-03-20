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
