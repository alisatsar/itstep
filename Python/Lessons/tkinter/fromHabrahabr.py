from random import *
from tkinter import *
from tkinter import colorchooser

window = Tk() #создание окна tkinter
colorchooser.askcolor() #открывает окно выбора цвета и возвращает кортеж из двух значений: кортеж из трех элементов,
# интенсивность каждой RGB цвета, и строка. цвет в шестнадцатиричной системе.

size = 600
root = Tk() #создаем окно;
canvas = Canvas(root, width=size, height = size)#создаем холст, используя значение переменной size
canvas.pack()#указание расположить холст внутри окна;
diapason = 0

while True: #diapason < 1000:
    colors = choice(['aqua', 'blue', 'fuchsia', 'green', 'maroon',
                     'orange', 'pink', 'purple', 'red', 'yellow', 'violet', 'indigo', 'chartreuse', 'lime', "#f55c4b"])
    x0 = randint(0, size)#случайный выбор координат х и у в рамках холста размером size.
    y0 = randint(0, size)
    d = randint(0, size/5)#произвольный выбор размера круга, ограниченный size/5.
    canvas.create_oval(x0, y0, x0+d, y0+ d, fill=colors)
    root.update() #обрабатывает все задачи, стоящие в очереди. Обычно эта функция используется
    # во время «тяжёлых» расчётов, когда необходимо чтобы приложение оставалось отзывчивым на действия пользователя.
    diapason += 1
