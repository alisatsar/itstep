>>> S = ‘Spam’
>>> len(S)      # Длина
4
>>> S[0]       # Первый элемент в S, счет начинается с позиции 0
‘S’
>>> S[1]       # Второй элемент слева
‘p’

>>> S[-1]       # Последний элемент в конце S
‘m’
>>> S[-2]       # Второй элемент с конца
‘a’

>>> S[-1]       # Последний элемент в S
‘m’
>>> S[len(S)-1]       # Отрицательная индексация, более сложный способ
‘m’

>>> S       # Строка из 4 символов
‘Spam’
>>> S[1:3]      # Срез строки S начиная со смещения 1 и до 2 (не 3)
‘pa’

>>> S[1:]       # Все, кроме первого элемента (1:len(S))
‘pam’
>>> S       # Сама строка S без изменений
‘Spam’
>>> S[0:3]      # Все, кроме последнего элемента
‘Spa’
>>> S[:3]       # То же, что и S[0:3]
‘Spa’
>>> S[:-1]      # Еще раз все, кроме последнего элемента, но проще (0:-1)
‘Spa’
>>> S[:]       # Все содержимое S, как обычная копия (0:len(S))
‘Spam’

>>> S
‘Spam’
>>> S + ‘xyz’       # Конкатенация
‘Spamxyz’
>>> S       # S остается без изменений
‘Spam’
>>> S * 8       # Повторение
‘SpamSpamSpamSpamSpamSpamSpamSpam’

СТРОКИ НЕИЗМЕНЯЕМЫ!!!
>>> S
‘Spam’
>>> S[0] = ‘z’       # Неизменяемые объекты нельзя изменить
                      ...текст сообщения об ошибке опущен...
                       TypeError: ‘str’ object does not support item assignment
>>> S = ‘z’ + S[1:]      # Но с помощью выражений мы можем создавать новые объекты
>>> S
‘zpam

>>>  S.find(‘pa’)            # Поиск смещения подстроки
1
>>>  S
‘ Spam’
>>>  S.replace(‘pa’, ‘XYZ’)   # Замена одной подстроки другой
‘SXYZm’
>>>  S
‘Spam’
>>>  line = ‘ aaa, bbb, ccccc, dd’
>>>  line. split(‘,’)   # Разбивает строку по разделителю и создает список строк
[‘aaa’, ‘bbb’, ‘ccccc’, ‘dd’]
>>>  S = ‘spam’
>>>  S.upper()          # Преобразование символов в верхний и в нижний регистр
‘ SPAM’
>>>  S.isalpha()        # Проверка содержимого: isalpha, isdigit и так далее
True
>>>  line = ‘aaa,bbb,ccccc,dd\n’
>>>  line = line. rstrip()  # Удаляет завершающие пробельные символы
>>>  line
‘ aaa, bbb, ccccc, dd’ 

>>>  ‘%s, eggs, and %s’ % (‘spam’, ‘SPAM!’)        # Выражение (во всех версиях)
‘spam, eggs, and SPAM!’

>>>  ‘{0}, eggs, and {1}’.format(‘spam’, ‘SPAM!’)     # Метод (2.6, 3.0)
‘spam, eggs, and SPAM!’

s = 'spam'
print(s.upper()) #Выводит в верхний регистр
print(""" sflafjlg
lsjfls
sgjoq sklg;sag""") #отображает текст так как он написан

print(s.lower()) #выводит мелкими

print(s.title()) #все большие первые буквы слов

print(s.replace("s", "z")) #замена слова или буквы во всем тексте

print(s.swapcase()) #меняет наоборот регистр

print(s) #меняет наоборот регистр

print("and", end = "123") #параметр добавляет строку к предидущему слову and

print("it...")

print(123 // 14) #показывает целое значение через //

car = input("your kredit")
car = int(car)
