import pygame
pygame.font._init_()

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

#герой
hero = Sprite(380, 540, "hero.png")

#цель
zet = Sprite(380, 0, "zet.png")
zet.Right = True

#молния
lightning = Sprite(380, 550, "lightning.png")
lightning.push = False

done = True
pygame.key.set_repeat(1000, 1) #1е значение - задержка перед первым дублированием
#2е задержка между остальным дублированием

while done:
    #обработчик событий
    for e in pygame.event.get():
        if e.type == pygame.QUIT:
            done = False
        #событие нажатия клавиш
        if e.type == pygame.KEYDOWN:
            if e.key == pygame.K_LEFT:#перемещение героя
                if hero.x > 10:
                    hero.x -= 1
            if e.key == pygame.K_RIGHT:
                if hero.x < 350:
                    hero.x -= 1

    #заливка экрана
    screen.fill((50, 50, 50))

    #передвижение цели
    if zet.Right == True:
        zet.x += 1
        if zet.x > 736:
            zet.Right = False
    else:
        zet.x -= 1
        if zet.x < 0:
            zet.Right = True

    lightning.render()
    hero.render()
    zet.render()


    window.blit(screen, (0,0)) #отображаем игровой экран скрин
    pygame.display.flip() #показать игровое окно
    pygame.time.delay(3) #задержка в милисекундах
