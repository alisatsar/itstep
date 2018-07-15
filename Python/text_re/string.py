>>> 'spam eggs ham'[5:9]    # извлечение среза: подстрока
'eggs'
>>> 'spam eggs'[:1]
's'
>>> 'spam ' + 'eggs ham'
'spam eggs ham'
>>> 'spam %s %s' %('eggs', 'ham')   # выражение форматирования: подстановка
'spam eggs ham'
>>> 'spam {} {}'.format('eggs', 'ham')    # метод форматирования: альтернатива %
'spam eggs ham'


>>> s = 'hello my dear world'
>>> s.find('hello')   #Выполняет поиск подстроки
0
>>> s.replace('hello', 'bye')   #Выполняет подстановку подстроки.
'bye my dear world'
>>> s.split()    #Разбивает строку по указанному разделителю или пробельным символам.
['hello', 'my', 'dear', 'world']
>>> s.join(' ! ')   #Объединяет подстроки, вставляя разделители между ними.
' hello my dear world!hello my dear world '
>>> s.strip()
'hello my dear world'
>>> 
>>> s.rstrip()
'hello my dear world'
>>> s.upper()
'HELLO MY DEAR WORLD'


>>> template = '---$target1---$target2---'
>>> template = template.replace('$target1', 'spam')
>>> template = template.replace('$target2', 'shrubbery')
>>> template
'---spam---shrubbery---'

>>> template = """
---
---%(key1)s---
---%(key2)s---
"""
>>> vals = {}
>>> vals['key1'] = 'Spam'
>>> vals['key2'] = 'shrubbery'
>>> print(template % vals)
---
---Spam---
---shrubbery---
>>> import string
>>> template = string.Template('---$key1---$key2---')
>>> template.substitute(vals)
'---Spam---shrubbery---'
>>> template.substitute(key1='Brian', key2='Loretta')
'---Brian---Loretta---'
>>> 
