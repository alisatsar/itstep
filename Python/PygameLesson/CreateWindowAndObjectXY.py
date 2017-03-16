import pygame

#создаем окно с размерами кортежа 600 х 600
window = pygame.display.set_mode((800, 600))
#название окна
pygame.display.set_caption("Black Jack")

screen = pygame.Surface((800, 600))#создание объекта

square = pygame.Surface((40, 40))#создание другого объекта
square.fill((0,255,78))

x = 0 #переменная для хождения объекта square по оси x
squareGoRight = True
y = 0 #переменная для хождения объекта square по оси y
squareGoDown = True

done = True
while done:
    for e in pygame.event.get():
        if e.type == pygame.QUIT:
            done = False

    #screen.fill((0, 35, 53))#Покрасить холст

    if squareGoRight == True:
        x += 1
        if  x > 760:
            squareGoRight = False
    else:
        x -= 1
        if x < 0:
            squareGoRight = True

    if squareGoDown == True:
        y += 1
        if y > 560:
            squareGoDown = False
    else:
        y -= 1
        if y < 0:
            squareGoDown = True

    screen.blit(square, (x, y))#отобразить на Объект screen объект square
    window.blit(screen, (0,0)) #отображаем игровой экран скрин
    pygame.display.flip() #показать игровое окно
    pygame.time.delay(3) #задержка в милисекундах
