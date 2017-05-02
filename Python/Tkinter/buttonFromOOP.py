import sys
from tkinter import*
widget = Button(None, text = "Hello world", command = sys.exit)
widget.pack()
mainloop()

from tkinter import*
root = Tk()
Label(root, text = "hello").pack()
Button(root, text = "Close window", command = root.destroy).pack(side = LEFT, expand = YES)
#root.destroy закрывает одно окно
#root.quit закрывает все окна
root.mainloop()

____СОБСТВЕННЫЙ ОБРАБОТЧИК СОБЫТИЙ
import sys
from tkinter import*

def quit():
    print("Hello world")
    sys.exit()

widget = Button(None, text = "hello world", command = quit)
widget.pack()
mainloop()


____ИСПОЛЬЗОВАНИЕ LAMBDA-ВЫРАЖЕНИЙ
import sys
from tkinter import*
widget = Button(None, text = "hello world",
                command = (lambda: print("Hello lambda world") or sys.exit()))
widget.pack()
mainloop()


____ССЫЛКА НА ФУНКЦИЮ В ОБРАБОТЧИКЕ СОБЫТИЙ
from tkinter import*

def handler(a):
    print(a)

def func():
    handler("hi")

widget = Button(None, text = "hello world", command = func)  #ссылка на функцию func, a не ее вызов
widget.pack()
mainloop()


____ИСПОЛЬЗОВАНИЕ КЛАССОВ  И ОТРАБОТКА ФУНКЦИИ ПОСЛЕ ИХ ВЫЗОВА
import sys
from tkinter import*

class HelloClass:
    def __init__(self):
        widget = Button(None, text="hello", command=self.quit)
        widget.pack()

    def quit(self):
        print("hello class method world")   #self.quit связанный метод хранит пару self+quit
        sys.exit()

HelloClass()
mainloop()

_____СВЯЗЫВАНИЕ С ПОМОЩЬЮ СПЕЦИАЛЬНОГО МЕТОДА __сall__
import sys
from tkinter import*

class HelloClass:
    def __init__(self):
        self.msg = 'hello __call__ world'

    def __call__(self):
        print(self.msg)   
        sys.exit()

widget = Button(None, text="hello", command=HelloClass())
widget.pack()
mainloop()
_______________________________________________________________

from tkinter import *
class But_print:
    def __init__(self):
        self.but = Button(root)     #Button(root) встроенный класс
        self.but["text"] = "Печать"
        self.but.bind("<Button-3>",self.printer)
        self.but.pack()     #встроенный менеджер размещения
    def printer(self,event):
        print ("Как всегда очередной 'Hello World!'")
root = Tk()
root.title("Main Window")
root.geometry("250x250")
obj = But_print()
root.mainloop()
