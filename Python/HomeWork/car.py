"""Нужно написать программу "Автомобиль". В программе может быть один или несколько классов,
в каждом из которых прописаны необходимые атрибуты и методы. Объект Автомобиль должен иметь необходимый функционал:
(Напрмиер)
1. Зажигание
2. Езда
3. Тормоз
4. Остановка двигателя
5. Включение фар
6. Открытие и закрытие дверей

Функциональность Автомобиля должна соответствовать логике, т.е. например, нельзя завести автомобиль два раза подрят.
Нельзя начать езду если нажат тормоз и так далее."""

class Car ():
    def __init__ (self, movement, brake, engineCondition, door):
        self.movement = movement
        self.brake = brake
        self.engineCondition = engineCondition
        self.door = door

    def Doors(self):
        if (self.door):
            print("Your door is open")
        else:
            print("Your door is closet")

    def StartMove(self):
        if (self.door == 1):
            if (self.engineCondition == 1):
                print("Your engine is start")
            else:
                print("Start the engine")
        else:
            print("You are don't start move")


print("You are stay near your car!\n")
print("Enter what you want to do:\n1 - Go to door\n2 - Start to engine\n3 - Go\n4 - Stop\n")

doorCondition = False
brakeCondition = False
engineCondition = False
movement = False

car = Car(movement, brakeCondition, engineCondition, doorCondition)

userChoose = int(input())
if (userChoose == 1):
    print("The door of your car is closed!\n")
    doorCondition = int(input("Please, enter 1 to open door, or 0\n"))
    car.Doors()


print("If you want to go, then start the engine!\n")
engineCondition = int(input("Please, enter 1 to start engine, or 0 to stop\n"))

print("If you want to stop, then press the brake!\n")
brakeCondition = int(input("Please, enter 1 to press the brake\n"))

print("If you want to move, then press the start movement!\n")
movement = int(input("Please, enter 1 to press the movement\n"))


car.Doors()
car.StartMove()
