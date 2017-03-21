"""class Colors:
    color = "red"
    def out(self):
        print(self.color)
    def addAnotherColor(self):
        print(self.color)
        print("Yellow")

object = Colors()
object.out()

object.addAnotherColor()

print(object.color)

class Second:
    color = "red"
    form = "circle"
    transparent = 50

    def changeColor(self, newcolor):
        self.color = newcolor
    def changeForm(self, newForm):
        self.form = newForm
    def changeTransparent(self, increase):
        self.transparent = increase


obj1 = Second()
obj2 = Second()

print(obj1.color, obj1.form)
print(obj2.color, obj2.form)

obj1.changeColor("Green")
obj1.changeColor("Blue")
obj2.changeForm("Oval")

print(obj1.color, obj1.form)
print(obj2.color, obj2.form)

obj1.changeTransparent(60)
print(obj1.transparent)

class Colors:
    color = "yellow"
    transparent = 50
    def changeColor(self, newColor, newtransparent):
        self.color = newColor
        self.transparent = newtransparent

class Position:
    color = "blue"
    transparent = 50
    def changeObject1(self, newColor, newTransparent):
        self.color = newColor
        self.transparent = newTransparent

obj1 = Colors()
obj2 = Position()

print(obj1.color)
obj1.changeColor("red", 70)
print(obj1.color)
print(obj1.transparent)

class First:
    color = "red"

    def output(self):
        print(self.color)

class Second:
    color = "Blue"

    def changeColor(self, newcolor):
        self.color = newcolor

obj1 = First()
obj1.output()

obj2 = Second()
print(obj2.color)

obj2 = Second()
print(obj2.color)
obj2.changeColor(obj1.color)
print(obj2.color)"""

class Critter(object):
    def __init__(self, name):
        print("a new critter has been born")
        self.name = name

    def __str__(self):
        rep = "critter object with name: " + self.name + "\n"
        return rep

    def talk(self):
        print("\nНello, i'm new instance")

class Another(object):
    def __init__(self, age, city):
        print("hello, i'm has been born too")
        self.age = age
        self.city = city

    def __str__(self):
        rep = "I'm " + self.age + "year old, and i'm living in " + self.city
        return rep

    def talk(self):
        print("I'm chubby")

obj1 = Critter("Sam")
obj1.talk()

obj2 = Critter("helen")
obj2.talk()

print(obj1)
print(obj2)

obj1 = Another("25", "Moscow")
obj1.talk()

obj2 = Another("18", "Minsk")
obj2.talk()

print(obj1)
print(obj2)
