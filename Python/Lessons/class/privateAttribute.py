class Critter(object):
    def __init__(self, name, mood):
        print("Hello")
        self.name = name
        self.__mood = mood      #приватный атрибут

    def talk(self):
        print("i'm", self.name)
        print("my mood now ", self.__mood)

    def __private_method(self):     #приватный метод
        print("private")

    def public_method(self):
        print("public")
        self.__private_method()

    def __another_private_method(self):
        print("I'm sad")

    def another_mood(self):
        print("Mood")
        self.__another_private_method()

crit = Critter(name = "Poochie", mood = "happy")
crit.talk()
crit.public_method()
crit.another_mood()



class Critter(object):
    total = 0

    @staticmethod #декоратор, который говорит следующий метод будет относиться к целому классу
    def status():
        print("my mood now sad")

    def __init__(self, name):
        print("Hello")
        self.name = name
        Critter.total += 1

print("Accessing the class attribute Critter.total:", end = ' ')
print(Critter.total)

print("\nCreating critters.")
crit1 = Critter("critter 1")
crit2 = Critter("critter 2")
crit3 = Critter("critter 3")

Critter.status()

print("\nAccessing the class attribute through an object:", end = ' ')
print(crit1.total)
