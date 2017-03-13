D = {‘food’: ‘Spam’, ‘quantity’: 4, ‘color’: ‘pink’}
D[‘food’]             #Получить значение, связанное с ключом ‘food’
D[‘quantity’] += 1    #Прибавить 1 к значению ключа ‘quantity’


D = {}
D[‘name’] = ‘Bob’     #В результате присваивания создается ключ
D[‘job’] = ‘dev’
D[‘age’] = 40
print(D)
{‘age’: 40, ‘job’: ‘dev’, ‘name’: ‘Bob’}
print(D[‘name’])

rec = {‘name’: {‘first’: ‘Bob’, ‘last’: ‘Smith’},
 ‘ job’: [‘ dev’, ‘ mgr’],
 ‘age’: 40.5}

rec[‘name’]           # ‘Name’ – это вложенный словарь
{‘ last’: ‘ Smith’, ‘ first’: ‘ Bob’}
rec[‘ name’][‘ last’]   # Обращение к элементу вложенного словаря
‘ Smith’
rec[‘job’]           # ‘Job’ – это вложенный список
[‘ dev’, ‘ mgr’]
rec[‘job’][-1]       # Обращение к элементу вложенного списка
‘ mgr’
rec[‘job’].append(‘janitor’) # Расширение списка должностей Боба (Bob)
rec
{‘ age’: 40.5, ‘ job’: [‘ dev’, ‘ mgr’, ‘ janitor’], ‘ name’: {‘ last’: ‘ Smith’, 
‘ first’: ‘Bob’}}

 rec = 0 
