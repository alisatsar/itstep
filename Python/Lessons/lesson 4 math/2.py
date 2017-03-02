#2. Длина Московской кольцевой автомобильной дороги —109 километров.
# Байкер Вася стартует с нулевого километра МКАД и едет со скоростью v километров в час.
# На какой отметке он остановится через t часов?
#Программа получает на вход значение v и t. Если v>0, то Вася движется в положительном направлении по МКАД,
# если же значение v<0, то в отрицательном.
#Программа должна вывести целое число от 0 до 108 — номер отметки, на которой остановится Вася

import math

lengthRoad = 109 #длина дороги в км
#вводится скорость мотоциклиста
speedMotorcyclist = int(input('Enter the speed of the motorcyclist: "-" if the movement has opposite direction'
                              'or "+" if movement has positive direction: '))

#вводится время которое он проехал мотоциклиста
timeMotorcyclist = int(input("Enter the time that the motorcyclist was traveling in minute: "))

pointStoping = timeMotorcyclist / 60 * speedMotorcyclist

if speedMotorcyclist > 0:
    while pointStoping > lengthRoad:
        pointStoping =  lengthRoad - pointStoping
        pointStoping = abs(pointStoping)
else:
    pointStoping = abs(pointStoping)
    while pointStoping > lengthRoad:
        pointStoping =  lengthRoad - pointStoping
        pointStoping = abs(pointStoping)

print("The point of stoping = ", int(pointStoping), " km")

input("Press enter to continue...")
