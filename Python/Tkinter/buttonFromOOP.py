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
