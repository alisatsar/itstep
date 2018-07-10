myfile = open(filename, ‘w’)
try:
...обработка myfile...
finally:
myfile.close()

with open(filename, ‘w’) as myfile:
  #... обработка myfile, закрывается автоматически после выхода...
  
>>> file.seek(0) # перейти в начало файла
>>> file.read() # прочитать в строку файл целиком
‘Hello file world!\nBye file world.\n’
>>> file.seek(0)
>>> file.readlines() # прочитать файл целиком в список строк
[‘Hello file world!\n’, ‘Bye file world.\n’]
>>> file.seek(0)
>>> file.readline() # читать по одной строке
‘Hello file world!\n’
>>> file.readline()
‘Bye file world.\n’
>>> file.readline() # конец файла – возвращается пустая строка
‘’
>>> file.seek(0) # прочитать N (или оставшиеся) символы/байты
>>> file.read(1), file.read(8) # конец файла – возвращается пустая строка
(‘H’, ‘ello fil’)
