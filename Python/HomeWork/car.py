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

    def StartEngine(self):
        if (self.engineCondition == 1):
            print("Your engine is start")
        else:
            print("The engine is not start")

    def StartMove(self):
        if (self.movement == 1):
            print("You move")
        else:
            print("You not move!")

    def StopCar(self):
        if (self.brake == 1):
            print("You are to stop the car")
        else:
            print("Your car still move!")


print("You are stay near your car!\n")

doorCondition = False
brakeCondition = False
engineCondition = False
movement = False

userChoose = 1
while (userChoose != 0):
    print("Enter what you want to do:\n1 - Go to door\n2 - Start to engine\n3 - Go\n4 - Stop\n5 - Exit from program\n")
    userChoose = int(input())
    if (userChoose == 1):
        print("The door of your car is closed!\n")
        doorCondition = int(input("Please, enter 1 to open door, or 0 to not open.\n"))
        car = Car(movement, brakeCondition, engineCondition, doorCondition)
        car.Doors()
    if (userChoose == 2):
        if (doorCondition):
            print("If you =want to go, then start the engine!\n")
            engineCondition = int(input("Please, enter 1 to start engine, or 0 to not start\n"))
            car = Car(movement, brakeCondition, engineCondition, doorCondition)
            car.StartEngine()
        else:
            print("The door of your car is closed!\n")
    if (userChoose == 3):
        if (engineCondition):
            print("Now you make start to go!\n")
            movement = int(input("Enter 1 to start, or 0 to not start\n"))
            car = Car(movement, brakeCondition, engineCondition, doorCondition)
            car.StartMove()
        else:
            print("The engine is not start")
    if (userChoose == 4):
        if (movement):
            print("You want to stop the car?\n")
            movement = int(input("Enter 1 to stop, or 0 to not stop\n"))
            car = Car(movement, brakeCondition, engineCondition, doorCondition)
            car.StopCar()
        else:
            print("The engine is not start")
    if (userChoose == 5):
        break
