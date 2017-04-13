li = ["red","green"]
def color(event):
     fra.configure(bg=li[0])        #метод общий для всех классов для изменения атрибутов в классах tkinker
     li[0],li[1] = li[1],li[0]      #меняется значения в листе 
 
def outgo(event):
     root.destroy()     #окошко закрывается
 
from tkinter import *
root = Tk()
 
fra = Frame(root,
            width=100,
            height=100)
but = Button(root,
             text="Выход")
 
fra.pack()
but.pack()
 
root.bind("<Return>",color)     #return это введение enter
but.bind("<Button-1>",outgo)
 
root.mainloop()
