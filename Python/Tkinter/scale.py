from tkinter import *
 
root = Tk()
#Рамки 
fra1 = Frame(root,      #для создания рамки
             width = 500,
             height = 100,
             bg = "darkred")
fra2 = Frame(root,
             width = 300,
             height = 200,
             bg = "#ffffff",
             bd = 20)   #Меняется отступ
fra3 = Frame(root,
             width = 500,
             height = 150,
             bg = "darkblue",
             bd = 40)
 
fra2.pack()
fra1.pack()
fra3.pack()

#Рамка в рамке
fra4 = Frame(fra2, #находится внутри элемента fra2
             width = 200,
             height = 100,
             bg = 'gray',
             bd = 25)
fra4.pack()

#Строка в рамке
ent1 = Entry(fra4, width = 20) #fra4 где находится
ent1.pack() 

#Шкалы
sca1 = Scale(fra3,
             orient = HORIZONTAL, #ориентация
             length = 300,  #длина
             from_ = 0,     #откуда 
             to = 100,      #до куда исчесление 
             tickinterval = 10,     #шаг отображения значений
             resolution = 10)       #шаг на который можно отодвигать
sca2 = Scale(root,
             orient = VERTICAL,
             length = 400,
             from_ = 1,
             to = 2,
             tickinterval = 0.1,
             resolution = 0.1)
sca1.pack()
sca2.pack()

root.mainloop() 
