from tkinter import *

window = Tk()

class Button_number:
    def __init__(self, value, xpos, ypos):
        self.value = value
        self.button = Button(window, text = value, bg='#151515', fg='#00E676', font='helvetica 16')
        self.button.bind("<Button-1>", self.click)
        self.button.place(x = 10 + xpos, y = 100 + ypos, width=50, height=50)

    def click (self, event):
        text.insert(END, self.value)


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
button1 = Button_number("1", 0, 0)
button2 = Button_number("2", 70, 0)
button3 = Button_number("3", 140, 0)
button4 = Button_number("4", 0, 70)
button5 = Button_number("5", 70, 70)
button6 = Button_number("6", 140, 70)
button7 = Button_number("7", 0, 140)
button8 = Button_number("8", 70, 140)
button9 = Button_number("9", 140, 140)
buttonDot = Button_number(".", 0, 210)
button0 = Button_number("0", 70, 210)
buttonDeleteChar = Button_number("<", 140, 210)

buttonPlus = Button_number("+", 230, 0)
buttonPercent = Button_number("%", 300, 0)
buttonMinus = Button_number("-", 230, 70)
buttonDegree = Button_number("x*y", 300, 70)
buttonMultiple = Button_number("*", 230, 140)
buttonDivideToX = Button_number("1/x", 300, 140)
buttonDevide = Button_number("/", 230, 210)
buttonRoot = Button_number("root", 300, 210)
buttonEqual = Button_number("=", 300, 280)

result = []

background.pack()
window.mainloop()
