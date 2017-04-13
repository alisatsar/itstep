#1. Создайте приложение, в котором меняется размер фрейма в зависимости от того, какая из трех объектов-кнопок была нажата.

from tkinter import *

def changeWindowSize250x250(event):
    root.geometry("250x250")

def changeWindowSize500x500(event):
    root.geometry("500x500")

def changeWindowSize800x800(event):
    root.geometry("800x800")

root = Tk()
root.title("Change the size of window! ")

root.geometry("100x100")

button250x250 = Button(root, text = "250x250", width = 10)
button500x500 = Button(root, text = "500x500", width = 10)
button800x800 = Button(root, text = "800x800", width = 10)

button250x250.grid(row=1,column=3)
button500x500.grid(row=2,column=3)
button800x800.grid(row=3,column=3)

button250x250.bind('<Button-1>',changeWindowSize250x250)
button500x500.bind('<Button-1>',changeWindowSize500x500)
button800x800.bind('<Button-1>',changeWindowSize800x800)

root.mainloop()
