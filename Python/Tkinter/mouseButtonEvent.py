import sys
from tkinter import*

def hello(event):
    print("Press twice to exit")

def quit(event):
    print("Hello, i must be going...")
    sys.exit()

widget = Button(None, text="hello")
widget.pack()
widget.bind('<Button-1>', hello)        #привязать обработчик щелчка левая кнопка мыши
widget.bind('<Double-1>', quit)         #привязать обработчик щелчка левая кнопка мыши двойно щелчок
mainloop()

_____________________________________________________
from tkinter import *

def printer(event): #специальный класс, методы которого связывают 
    print("Как всегда очередной 'Hello World!'")

root = Tk()
root.title("Main Window")
root.geometry("250x250")

but = Button(root)  #ВСТроенный класс для создания кнопки
but["text"] = "Печать"      #то, что надо написать в кнопке
but.bind("<Button-2>", printer)     #метод класса баттон который ожидает какое-то событие
#ввод события от мышкизапуск мышки 1 - левая. 2 колесико. 3 правая

but.pack()  #менеджер размещений
root.mainloop()
