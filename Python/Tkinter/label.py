from tkinter import *           #импортировать виджет
root = Tk()         #cоздаем родительское окно, если не создаем, то оно создается автоматически
widget = Label(None, text = "Hello world")          #создать его
widget.pack(side = BOTTOM)           #разместить
widget.mainloop()       #запустить цикл событий

from tkinter import*
Label(None, text="Hello world").pack(side=BOTTOM)
mainloop()

from tkinter import*
Label(None, text="Hello world").pack(expand=YES, fill=BOTH)  #expand и fill используются для заполнения пространства окна
mainloop()

from tkinter import *
root = Tk()
widget = Label(root)
widget.config(text="Hello world", font="Helvetica")
widget.pack(side=TOP, expand=YES, fill=BOTH)      #метод pack() возвращает None, поэтому его надо использовать отдельно от создания объекта
root.title("My program")            #этот метод устанавливает текст в заголовке окна
widget.configure(text="Good bye")   #метод для изменения атрибутов объекта
mainloop()
