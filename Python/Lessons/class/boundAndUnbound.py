__________________BOUND AND UNBOUND METHOD__________________

class Cat:
    def __init__(self):
        self.hungry = True
    def eat(self):
        if self.hungry:
            print("i am hungry")
            self.hungry = False
        else:
            print("No, thanks!")

class Barsik(Cat):
    def __init__(self):
        Cat.__init__(self)
        self.sound = "Aaaaaaaa"
        print(self.sound)

brs = Barsik()
brs.eat()
