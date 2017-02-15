x = 'killer rabbit'
if x == 'roger':
    print("how’s jessica?")
elif x == 'bugs':
    print("what’s up doc?")
else:
    print("Run away! Run away!")
   
choice = 'ham'
print ({'spam': 1.25,'ham': 1.99, 'eggs': 0.99,'bacon': 1.10}[choice]) # Инструкция ‘switch’ на базе словаря
# Используйте has_key или get для значения по умолчанию
#Эквивалентно
if choice == 'spam':
    print(1.25)
elif choice == 'ham':
    print (1.99)
elif choice == 'eggs':
    print(0.99)
elif choice == 'bacon':
    print(1.10)
else:
    print('Bad choice')

#Пример с использование метода get для получения значения по умолчанию
branch = {'spam': 1.25, 'ham': 1.99, 'eggs': 0.99}
print(branch.get('spam', 'Bad choice'))
print(branch.get('bacon', 'Bad choice'))

#Применение оператора in проверки на вхождение в инструкции if может
# обеспечить получение того же результата по умолчанию:
choice = 'ham'
if choice in branch:
    print(branch[choice])
else:
    print('Bad choice')
    
x = 'SPAM'
if 'rubbery' in 'shrubbery':
    print(x * 8)
    x += 'NI'                    # x = x + NI
    if x.endswith('NI'):        # если заканчивается на NI
        x *= 2
        print(x)                # Выведет “SPAMNISPAMNI”
        
X and Y                       #Истина, если оба значения X и Y истинны.
X or Y                          #Истина, если любое из значений X или Y истинно.
not X                         #Истина, значение X ложно (выражение возвращает значение True или False)


#В случае оператора or интерпретатор начинает вычислять значения объектов-
#операндов слева направо и возвращает первый, имеющий истинное значение.
>>>  2 or 3, 3 or 2      # Вернет левый операнд, если он имеет истинное значение
(2, 3)                  # Иначе вернет правый операнд (истинный или ложный)
>>>  [] or 3            #вернет левое значение, так как правое пустое - является False
3
>>>  [] or {}         #интерпретатор простовычисляет и возвращает объект справа (который может иметь как истинное,так и ложное значение).
{}

#Вычисление оператора and также останавливается, как только результат ста-
#нет известен, однако в этом случае интерпретатор вычисляет операнды слева
#направо и возвращает первый объект, имеющий ложное значение:
>>>  2 and 3, 3 and 2    # Вернет левый операнд, если он имеет ложное значение
(3, 2)                  # Иначе вернет правый операнд (истинный или ложный)
>>>  [] and {}
[]
>>>  3 and []
[]


if X:
    A = Y
else:
    A = Z
#Упрощенная запись
A =  Y if X else Z
