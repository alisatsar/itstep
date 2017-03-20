import pygame

pygame.init()
#создаем окно с размерами кортежа 600 х 600
window = pygame.display.set_mode((800, 600))
#название окна
pygame.display.set_caption("Black Jack")

screen = pygame.Surface((800, 600))#создание объекта

class Sprite:
    def __init__(self, xpos, ypos, filename):# xpos и ypos передают координаты объекта, filename путь к изображению объекта
        self.x = xpos #Задаются коодинаты
        self.y = ypos
        self.bitmap = pygame.image.load(filename) #получает ссылку загруженную с помощью функции pygame.image.load
        #self.bitmap.set_colorkey((255,255,255)) #указывает какой цвет у изображения нужно сделать прозрачным

    def render(self):
        screen.blit(self.bitmap, (self.x, self.y)) #отображение объекта на игровой экран

def Intersect(x1, x2, y1, y2):
    if (x1 > x2 - 40) and (x1 < x2 + 40) and (y1 > y2 - 40) and (y1 < y2 + 40):
        return 1
    else:
        return 0

hero = Sprite(380, 540, "hero.png")
hero.up = True
zet = Sprite(380, 0, "zet.png")
zet.goDown = True

done = True
while done:
    for e in pygame.event.get():
        if e.type == pygame.QUIT:
            done = False

    screen.fill((50, 50, 50))

    if hero.up == True:
        hero.y += 1
        if hero.y > 536:
            hero.up = False
    else:
        hero.y -= 1
        if hero.y < 0:
            hero.up = True

    if zet.goDown == True:
        zet.y += 1
        if zet.y > 536:
            zet.goDown = False
    else:
        zet.y -= 1
        if zet.y < 0:
            zet.goDown = True

    if Intersect(zet.x, hero.x, zet.y, hero.y) == True:
        hero.up = False
        zet.goDown = True

    hero.render()
    zet.render()

    window.blit(screen, (0,0)) #отображаем игровой экран скрин
    pygame.display.flip() #показать игровое окно
    pygame.time.delay(3) #задержка в милисекундах
