def simple():
    spam = "ni"
    def action():
        print(spam)     #ссылка на переменную Spam
    return action

act = simple()      #создать и вернуть вложенную функцию
act()               #вызываем вложенную функцию

_____

def simple():
    def action():
        return spam     #поиск ссылки будет происходить после вызова функции
    spam = "ni"
    return action

act = simple()      #создать и вернуть вложенную функцию
print(act())        #вызываем вложенную функцию

________

def weird():
    spam = 42
    handler = (lambda: spam * 2)    # функция не сохраняет текущее значение 42
    spam = 50
    print(handler())    # выведет 100: поиск spam выполняется именно сейчас
    spam = 60
    print(handler())    # выведет 120: поиск spam снова выполняется именно сейчас

weird()

_______


def odd():
    funcs = []
    for c in "abcdefg":
        funcs.append((lambda: c))       # поиск переменной c будет выполнен позднее
    return funcs        #вернет последнее значение с, то есть g

for func in odd():
    print(func(), end = " ")    #Вывод g g g g g g g
  
_______

def odd():
    funcs = []
    for c in "abcdefg":
        funcs.append((lambda c = c: c))       # запомнит с каждой итерации
    return funcs    #значения по умолчанию вычисляются немедленно

for func in odd():
    print(func(), end = " ")    #Вывод a b c d e f g 
