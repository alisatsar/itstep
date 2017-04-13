#1.Напишите следующую программу. На главном окне находится несколько чекбоксы и текстовое поле.
# При щелчке левой кнопкой мыши в пределах текстового поля в нем должны отображаться значения включенных флажки
# (появляться сообщение о том, какие флажки включены), при щелчке правой кнопкой мыши — значения выключенных флажков.
from tkinter import *

def __init__(self, root):
    self.var = IntVar()
    value1 = "RED"
    checkBoxRed = Checkbutton(root, text="red", variable=self.var, command=self.cb).pack()
    if s == "RED":
        field.delete(1.0, END)  # очистка экрана
        field.insert(END, "RED")
    else:
        field.delete(1.0, END)
        field.insert(END, " ")

root = Tk()
root.title("CheckBox")

root.minsize(width = 500, height = 500)
root.maxsize(width = 500, height = 500)

c1 = IntVar()
value1 = "RED"
checkBoxRed = Checkbutton(root, text="red", variable = c1, onvalue = value1, offvalue = False).pack()
checkBoxRed.var = c1

field = Entry(root, width = 30, bd = 2)
field.pack()

output(checkBoxRed)

root.mainloop()
