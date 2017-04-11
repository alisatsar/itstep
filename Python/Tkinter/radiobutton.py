
from tkinter import *

root = Tk()
root.title("Widjets 1")
root.geometry("220x900")

#Кнопка
but = Button(root,
             text = 'This is Button',           #встроенный параметры в модуле
             width = 30,
             height = 5,
             bg = 'Black',
             fg = 'blue',
             font = "Arial 18")

but.pack()

#Метка
lab = Label(root,
            text="Это метка! \n Из двух строк.",
            font="Arial 18")            #Класс для создания вывбодимого текста(метки)
lab.pack()

#Однострочное текстовое поле
ent = Entry(root, width=20, bd=3)       #Класс для создания полей одной строки, bd толщина рамки
ent.pack()

#Многострочное текстовое поле
tex = Text(root, width=20, height = 5,
          font="Verdana 12",
          wrap=WORD)        #для создания моногострочного поля, Wrap = WORD пененос слова по словам,
                            # Wrap = WORD пененос слова по буквам
                            # Wrap = NONE пененос Только после нажатия кнопки enter
tex.pack()

#Радиокнопки
var = IntVar()      #класс для создания радиобаттонов. все баттоны один объект
var.set(1)  #set какая активная, считаем с нуля
rad0 = Radiobutton(root, text="Первая",
                   variable=var, value=0).pack()        #variable к какому объкту привязываем объекты,
                                                        #  value числовой идентификатор
                                                        #pack() для отображения
rad1 = Radiobutton(root, text="Вторая",
                   variable=var, value=1)
rad2 = Radiobutton(root, text="Третья",
                   variable=var, value=2)
rad1.pack() #pack() для отображения(другой вариант)
rad2.pack()

#Флажки
c1 = IntVar()       #класс для создания чекбоксов, создаются отдельно
c2 = IntVar()
che1 = Checkbutton(root, text="Первый флажок",
                   variable=c1, onvalue=1, offvalue=0).pack()   #onvalue=1 выбран offvalue=0 не выбран с переданными
                                                            # значеними, если они одинаковые, то галочка не отжимается
che2 = Checkbutton(root,text="Второй флажок",
                   variable=c2, onvalue=1, offvalue=0)
che2.pack()

#Списки
r = ['Linux', 'Python', 'Tk', 'Tkinter'] #список для выбора пользователем
lis = Listbox(root, selectmode=SINGLE, height=4)    #Listbox для вывода списка, height количество выводимых элементов
                                                    #selectmode=SINGLE можно выбрать только один
#selectmode=EXTENDED можно выбрать несколько
for i in r:
     lis.insert(END,i) #вставка каждого элемента во внутрь нашего объекта
lis.pack()


root.mainloop()
