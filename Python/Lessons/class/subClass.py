class One():
    def meth1 (self, a, b):
        print("Line 1 - User 1")
        a.meth2()
        b.meth3()

class Two():
    def meth2(self):
        print("Line 2 - User 2")

class Tree():
    def meth3(self):
        print("Line 3 - User 3")

obj1 = One()
obj2 = Two()
obj3 = Tree()

obj1.meth1(obj2, obj3)

_________________________________
class One():
    c = 10
    def meth (self, a, b):
        print(self.c + a + b)

class Two():
    def meth(self, a):
        self.meth = len(str(a))
        return self.meth


obj1 = One()
obj2 = Two()

obj1.meth(45, 55)
print(obj2.meth(100))

________________________________
class Base():
    def __init__ (self, variable):
        self.result = variable
    def out(self):
        self.result = self.result * 5
        print(self.result)

class SubClass(Base):
    def out(self):
        print("\n---")
        Base.out(self)
        print("---")

obj1 = Base(15)
obj2 = SubClass(30)

obj1.out()
obj2.out()

_____________________________________________
class Base:
    def __init__ (self, variable):
        self.result = variable
    def out(self):
        print(self.result)

class SubClass(Base):
    def multiple(self, z):
        self.result *= z
        print("---")

class SubSubClass(SubClass):
    def devide(self, q):
        self.result /= q
        print("....")
    def out(self):
        print(self.result*100)

obj1 = Base(15)
obj2 = SubClass(15)
obj3 = SubSubClass(9)

obj1.out()
obj2.multiple(5)
obj2.out()
obj3.devide(3)
obj3.multiple(2)
obj3.out()
