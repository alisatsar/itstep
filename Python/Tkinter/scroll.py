from tkinter import *
 
root = Tk()

#Полоса прокрутки
text = Text(root, height=3, width=60)
text.pack(side='left')      #текст с левой стороны
scrollbar = Scrollbar(root)     #cоздание скролла
scrollbar.pack(side='left')     #нодится слева
# первая привязка
scrollbar['command'] = text.yview #по оси у
# вторая привязка
text['yscrollcommand'] = scrollbar.set
root.mainloop()

#Окно верхнего уровня

win = Toplevel(root,
               relief = SUNKEN,
               bd = 10,
               bg = "lightblue")
win.title("Дочернее окно")
win.minsize(width = 400, height = 200) 

root.mainloop() 
