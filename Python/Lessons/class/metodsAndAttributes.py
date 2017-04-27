_________________________PRIVATE AND INIT______________________________

class Simple:
    __private_a = 10        #приватный метод не доступный снаружи
    def __init__(self, count, str):         #конструктор, который при создании объекта одинаковые атрибуты и методы
        self.list = []      #при создании объекта будет создан пустой список
        self.count = count
        self.str = str
        self.__private_a = 20
        print(self.__private_a)

smp1 = Simple(1, 22)            #создание экземпляра класса
print(smp1.count)               #вызов атрибута
print(smp1.str)
print(smp1.__private_a)         #ошибка, так как метод не доступен снаружи

_______________________________METHOD_______________________________________

def methodForSimple(self, x, y):        #метод можно определять не в классах
    return x + y

class Simple:
    f = methodForSimple

s = Simple()
print(s.f(1, 2))

________________________________SELF________________________________________
class Simple:
    def __init__(self):     #self полезен для того, чтобы обращаться к другим атрибутам класса
        self.list = []
    def f1(self):
        self.list.append(123)
    def f2(self):
        self.f1()

s = Simple()
s.f2()
print(s.list)

___________________________INHERITANCE_______________________________________

class Derived():        #создаем базовый класс
    def __init__(self, q):
        self.q = q

class Derived2(Derived):        #создаем подкласс, который будет связан с базовым
    def Multiple(self):
        self.q = self.q + 10

s = Derived2(5)         
s.Multiple()
print(s.q)


class Derived(Base1,Base2,Base3)
поиск атрибутов происходит следующим образов:
    
в Derived;
в Base1, затем рекурсивно в базовых классах Base1;
в Base2, затем рекурсивно в базовых классах Base2
и т.д.
