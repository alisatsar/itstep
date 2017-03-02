#2.Байкер Вася стартует с нулевого километра МКАД и едет со скоростью v километров в час.
# На какой отметке он остановится через t часов?

import math

speedMotorcyclist = int(input("Enter the speed of the motorcyclist: ")) #вводится скорость мотоциклиста

#вводится время которое он проехал мотоциклиста
timeMotorcyclist = int(input("Enter the time that the motorcyclist was traveling in minute: "))


pointStoping = timeMotorcyclist / 60 * speedMotorcyclist

print("The point of stoping = ", pointStoping, " km")

input("Press enter to continue...")
