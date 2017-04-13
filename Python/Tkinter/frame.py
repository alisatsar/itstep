from tkinter import *

root = Tk()

f_1=Frame(root,width=50,height=50,bg="Yellow")      #frame - рамка
f_2=Frame(root,width=50,height=50,bg="Blue")
f_3=Frame(root,width=50,height=50,bg="Green")
f_4=Frame(root,width=50,height=50,bg="Red")

# Размещение рамок горизонтально
# Возможные параметры side: LEFT, RIGHT, TOP, BOTTOM
f_1.pack(side=LEFT)         #side=LEFT  элементы будут распологаться слева друг к другу
f_2.pack(side=LEFT)
f_3.pack(side=LEFT)
f_4.pack(side=LEFT)

f_1.pack()         #элементы будут распологаться по низу
f_2.pack()
f_3.pack()
f_4.pack()

f_1.pack(side=LEFT)       
f_2.pack(side=RIGHT)
f_3.pack(side=TOP)
f_4.pack(side=BOTTOM)

root.mainloop()



from tkinter import *
# Вариант 2х2

root = Tk()

f_01=Frame(root)
f_02=Frame(root)
f_1=Frame(f_01,width=50,height=50,bg="Yellow")
f_2=Frame(f_01,width=50,height=50,bg="Blue")
f_3=Frame(f_02,width=50,height=50,bg="Green")
f_4=Frame(f_02,width=50,height=50,bg="Red")

f_01.pack(side=LEFT)
f_02.pack(side=LEFT)
f_1.pack()
f_2.pack()
f_3.pack()
f_4.pack()

root.mainloop() 
