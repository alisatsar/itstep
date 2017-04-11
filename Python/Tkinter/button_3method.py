from tkinter import *

root = Tk()
root.title("New Window!")
root.geometry("500x500")

#app = Frame(root)
#app.grid()      #встроенный менеджер размещения позволяет разместить элементы на

bttn1 = Button(root, text = 'I do nothing!')        #root это где должна быть кнопка, text - это текст,
# размещает окна последовательно, если не указал где они должны находиться
bttn1.grid()

bttn2 = Button(root)
bttn2.grid()
bttn2.configure(text = 'I am too!') #посылает на что надо написать текст

bttn3 = Button(root)
bttn3.grid()
bttn3['text'] = 'And I!'    #посылает на что надо написать текст на кнопке

root.mainloop()
