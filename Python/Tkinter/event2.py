from tkinter import *
 
def exit_(event):
     root.destroy()
def caption(event):
     tex = ent.get()     #вводимый текст
     lbl.configure(text = tex) #отображение вводимого текста

root = Tk()
 
ent = Entry(root, width = 40)
lbl = Label(root, width = 80)
 
ent.pack()
lbl.pack()
 
ent.bind('<Return>',caption)
root.bind('<Control-z>',exit_)
 
root.mainloop()
