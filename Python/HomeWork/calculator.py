from math import*
from tkinter import *

window = Tk()

class Button_number:
    leftOperand = []    #list for left operand
    rightOperand = []   #list for right operand
    action = []         #list for action
    equal = []          #list for equal
    leftOperandValue = 0
    rightOperandValue = 0
    firstAction = []    #list for define first and next action
    def __init__(self, value, xpos, ypos):
        self.value = value
        self.button = Button(window, text = value, bg='#151515', fg='#00E676', font='helvetica 16', command=self.click)
        self.button.place(x = 10 + xpos, y = 100 + ypos, width=50, height=50)

    #when click to button to define first or next action
    def click(self):
        if self.firstAction != []:
            self.nextAction()
        else:
            self.actionFirst()

    #if action first
    def actionFirst(self):
        #fill left operand
        if (self.value.isnumeric() or self.value == ".") and self.rightOperand == [] and self.action == []:
            if self.value == ".":
                self.findDot(self.leftOperand)
            else:
                text.insert(END, self.value)
                self.leftOperand.append(self.value)
        #fill action
        elif self.value.isnumeric() == False and self.leftOperand != [] and self.rightOperand == []\
                and self.action == [] and self.value != "<" and self.value != "root" and self.value != ".":
            text.insert(END, self.value)
            self.action.append(self.value)
        #fill right operand
        elif (self.value.isnumeric() or self.value == ".") and self.leftOperand != [] and self.action != []:
            if self.value == ".":
                self.findDot(self.rightOperand)
            else:
                text.insert(END, self.value)
                self.rightOperand.append(self.value)

        if self.value == "=":
            self.firstAction.append('YES')
            self.leftOperandValue = self.convert(self.leftOperand)
            self.rightOperandValue = self.convert(self.rightOperand)
            self.calculate()
        elif self.value == "clear":
            self.clearField()
        elif self.value == "root":
            self.leftOperandValue = self.convert(self.leftOperand)
            self.countRoot(self.leftOperandValue)
        elif self.value == "<":
            self.deleteCharacter()

    #if action next
    def nextAction(self):
        if self.value.isnumeric() == False and self.rightOperandValue != [] and self.value != "=":
            self.rightOperand.clear()
        if self.value.isnumeric() == False and self.leftOperand != [] and self.rightOperand == [] \
             and self.action != [] and self.value != "<" and self.value != "root" and self.value != "=":
            self.action.clear()
            text.insert(END, self.value)
            self.action.append(self.value)
        elif self.value.isnumeric() and self.leftOperand != [] and self.action != []:
            text.insert(END, self.value)
            self.rightOperand.append(self.value)
        if self.value == '=':
            self.leftOperandValue = self.equal[0]
            self.rightOperandValue = self.convert(self.rightOperand)
            self.calculate()
        elif self.value == "clear":
            self.clearField()
        elif self.value == "root":
            self.leftOperandValue = self.equal[0]
            self.countRoot(self.leftOperandValue)
        elif self.value == "<":
            self.clearField()

    def clearField(self):
        self.leftOperand.clear()
        self.leftOperandValue = 0
        self.action.clear()
        self.rightOperand.clear()
        self.rightOperandValue = 0
        self.equal.clear()
        self.firstAction.clear()
        text.delete(1.0, END)

    def findDot(self, operand):
        i = 0
        countDot = 0
        while i < len(operand):
            if operand[i] == ".":
                countDot = 1
            i = i + 1
        if countDot == 0:
            text.insert(END, self.value)
            operand.append(self.value)

    def countRoot(self, a):
        self.equal = sqrt(a)
        text.delete(1.0, END)
        text.insert(END, self.equal)

    def deleteCharacter(self):
        if self.equal == []:
            if self.leftOperand != [0] and self.rightOperand == [] and self.action == []:
                self.leftOperand.pop()
                text.delete(1.0, END)
                self.uotputTextForScreen(self.leftOperand)
            elif self.leftOperand != [] and self.rightOperand == [] and self.action != []:
                text.delete(1.0, END)
                self.uotputTextForScreen(self.leftOperand)
                self.action.clear()
            elif self.leftOperand != [] and self.rightOperand != [] and self.action != []:
                self.rightOperand.pop()
                text.delete(1.0, END)
                self.uotputTextForScreen(self.leftOperand)
                text.insert(END, self.action[0])
                self.uotputTextForScreen(self.rightOperand)

    #convert list in int
    def convert(self, a):
        i = 0
        b = ''
        while i < len(a):
            b = b + a[i]
            i = i + 1
        return float(b)

    def calculate(self):
        self.equal.clear()
        if self.action[0] == "+":
            self.equal.append(self.leftOperandValue + self.rightOperandValue)
        elif self.action[0] == "-":
            self.equal.append(self.leftOperandValue - self.rightOperandValue)
        elif self.action[0] == "*":
            self.equal.append(self.leftOperandValue * self.rightOperandValue)
        elif self.action[0] == "/":
            if self.rightOperandValue == 0:
                text.delete(1.0, END)
                text.insert(END, "to zero cannot be split")
            else:
                self.equal.append(self.leftOperandValue / self.rightOperandValue)
        text.delete(1.0, END)
        text.insert(END, self.equal[0])

    def uotputTextForScreen(self, a):
        j = 0
        while j < len(a):
            text.insert(END, a[j])
            j = j + 1

window.title("Calculator!")

window.maxsize(width = 370, height = 370)
window.minsize(width = 370, height = 370)

text = Text(window, width=50, height = 5,
          font="Verdana 12",
          wrap=NONE)

text.pack()

background = Frame(window, width = 370, height = 500, bg = "#212121")

button1 = Button_number("1", 0, 0)
button2 = Button_number("2", 70, 0)
button3 = Button_number("3", 140, 0)
button4 = Button_number("4", 0, 70)
button5 = Button_number("5", 70, 70)
button6 = Button_number("6", 140, 70)
button7 = Button_number("7", 0, 140)
button8 = Button_number("8", 70, 140)
button9 = Button_number("9", 140, 140)
button0 = Button_number("0", 70, 210)
buttonDot = Button_number(".", 0, 210)
buttonDeleteChar = Button_number("<", 140, 210)
buttonPlus = Button_number("+", 230, 0)
buttonMinus = Button_number("-", 230, 70)
buttonDegree = Button_number("clear", 300, 0)
buttonMultiple = Button_number("*", 230, 140)
buttonDevide = Button_number("/", 230, 210)
buttonRoot = Button_number("root", 300, 70)
buttonEqual = Button_number("=", 300, 210)

background.pack()
window.mainloop()
