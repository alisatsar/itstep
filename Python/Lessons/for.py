for <target>  in <object>:    # Связывает элементы объекта с переменной цикла
    <statements>        # Повторяющееся тело цикла: использует переменную цикла
else:
    <statements>        # Если не попали на инструкцию ‘break’
for <target>  in <object>:  # Присваивает элементы объекта с переменной цикла
     <statements>
    if <test>: break       # Выход из цикла, минуя блок else
    if <test>: continue    # Переход в начало цикла
else:
     <statements>           # Если не была вызвана инструкция ‘break’


for x in ["e", "b", "c"]:
    print(x, end = " ")     #присвоим переменной x каждый из трех элементов списка 
    
sum = 0
b = 3
for x in [1, 2, 3, 4]:
    sum = sum + x
    b = b * x
    print(sum, end = " ")
    print(b, end = " ")
    
S = "lumberjack"
T = ("and", "I’m", "okay")
for x in S:
    print(x, end=" ")       # Обход строки
for x in T:
    print(x, end=" ")       # Обход элементов кортежа
    
T = [(1, 2), (3, 4), (5, 6)]
for (a, b) in T:             # Операция присваивания кортежа в действии
    print(a, b)
