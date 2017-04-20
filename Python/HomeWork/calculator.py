from tkinter import *

window = Tk()

leftOperand = 0
rightOperand = 0
movement = 0

class Calculate():
    def __init__(self, numbers):
        self.total = 0
        self.current = ""
        self.new_num = True
        self.op_pending = False
        self.op = ""
        self.eq = False

window.title("Calculator!") #заголовок окна

window.maxsize(width = 370, height = 500)
window.minsize(width = 370, height = 500)

text = Text(window, width=50, height = 5,
          font="Verdana 12",
          wrap=NONE)        #для создания моногострочного поля, Wrap = WORD пененос слова по словам,
                            # Wrap = WORD пененос слова по буквам
                            # Wrap = NONE пененос Только после нажатия кнопки enter
text.pack()

background = Frame(window, width = 370, height = 500, bg = "#212121")

#прописываем кнопки
allNumbers = "123456789"
button = []
i = 0
xpos = 0
ypos = 0
while (i < 9):
    if i == 1 or i == 4 or i == 6:
        xpos = 80
    elif i == 2 or i == 5 or i == 8:
        xpos = 150
    else:
        xpos = 10
    if i > 2 and i <= 5:
        ypos = 170
    elif i > 5 and i <= 8:
        ypos = 240
    else:
        ypos = 100
    button.append(Button(window, text = allNumbers[i], bg='#151515', fg='#00E676', font='helvetica 16'))
    button[i].place(x = xpos, y = ypos, width = 50, height = 50)
    i = i + 1


button0 = Button(window, text = "0", bg='#151515', fg='#00E676', font='helvetica 16')
button0.place(x = 80, y = 310, width = 50, height = 50)
buttonDeleteChar = Button(window, text = "<", bg='#151515', fg='#00E676', font='helvetica 16')
buttonDeleteChar.place(x = 150, y = 310, width = 50, height = 50)
buttonPlus = Button(window, text = "+", bg='#151515', fg='#00E676', font='helvetica 16')
buttonPlus.place(x = 240, y = 100, width = 50, height = 50)
buttonMinus = Button(window, text = "-", bg='#151515', fg='#00E676', font='helvetica 16')
buttonMinus.place(x = 240, y = 170, width = 50, height = 50)
buttonMultiple = Button(window, text = "*", bg='#151515', fg='#00E676', font='helvetica 16')
buttonMultiple.place(x = 240, y = 240, width = 50, height = 50)
buttonDivide = Button(window, text = "/", bg='#151515', fg='#00E676', font='helvetica 16')
buttonDivide.place(x = 240, y = 310, width = 50, height = 50)
buttonEqual = Button(window, text = "=", bg='#151515', fg='#00E676', font='helvetica 16')
buttonEqual.place(x = 310, y = 240, width = 50, height = 120)

result = []

background.pack()
window.mainloop()
