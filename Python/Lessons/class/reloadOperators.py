class Newclass():
    def __init__(self, base):
        self.base = base

    def __add__(self, a):           #позволяет добавлять к объекту значение
        self.base = self.base + a

    def __mul__(self, b):           #позволяет объетку быть умноженным
        self.base = self.base * b

    def __sub__ (self, c):          #позволяет от объекта отнять
        self.base = self.base - c

    def __call__(self, newWord):    #позволяет сделать объект как функцией
        self.base = newWord

    def __str__(self):              #представляет объект в виде строки, (можно принтануть объект),
        # а так возвращает адрес объекта
        return "%s !!!" % self.base

obj1 = Newclass(10)
obj1 + 20
print(obj1)

obj1 - 20
print(obj1)

obj1 * 2
print(obj1)

obj2 = Newclass("Yes")
obj2 + "terday"
print(obj2)
obj2 * 4
print(obj2)

obj2("No")
print(obj2)
