>>> import sys
>>> sys.platform #платформа
'win32'
о
>>> sys.maxsize #число max int
9223372036854775807
>>> sys.version #версия Python
'3.6.5 (v3.6.5:f59c0932b4, Mar 28 2018, 17:00:18) [MSC v.1900 64 bit (AMD64)]'
>>> sys.path #пути модуля
['', 'C:\\Users\\Tsarev\\AppData\\Local\\Programs\\Python\\Python36\\Lib\\idlelib', 'C:\\Users\\Tsarev\\AppData\\Local\\Programs\\Python\\Python36\\python36.zip', 'C:\\Users\\Tsarev\\AppData\\Local\\Programs\\Python\\Python36\\DLLs', 'C:\\Users\\Tsarev\\AppData\\Local\\Programs\\Python\\Python36\\lib', 'C:\\Users\\Tsarev\\AppData\\Local\\Programs\\Python\\Python36', 'C:\\Users\\Tsarev\\AppData\\Local\\Programs\\Python\\Python36\\lib\\site-packages']
>>> sys.argv #аргументы командной строки
['']
>>> import os
>>> os.getpid() #Id процесса
5552
>>> os.getcwd() #текущий рабочий каталог
'C:\\Users\\Tsarev\\AppData\\Local\\Programs\\Python\\Python36'
>>> os.chdir(r'C:\Users\Tsarev\Desktop') #поменять текущую директорию
>>> os.getcwd()
'C:\\Users\\Tsarev\\Desktop'
>>> os.sep #сепаратор для OC
'\\'
>>> os.linesep                  #символ перевода строки
'\r\n'
>>> os.path.isdir(r'C:\Users')  #это директория
True
>>> os.path.isfile(r'C:\Users')
False
>>> os.path.exists(r'C:\Users') #существует ли
True
>>> os.path.getsize(r'C:\Users\Tsarev\Desktop\my.py')   #Вовращает размер в байтах
303
>>> os.path.split(r'C:\Users\Tsarev\Desktop\my.py')    #отделяет дир от файла
('C:\\Users\\Tsarev\\Desktop', 'my.py')
>>> os.path.join(r'C:\Users\Tsarev\Desktop', 'my.py')   #соединяет дир. и файл
'C:\\Users\\Tsarev\\Desktop\\my.py'
>>> os.path.dirname(r'C:\Users\Tsarev\Desktop\my.py')   #вовращает директорию
'C:\\Users\\Tsarev\\Desktop'
>>> os.path.basename(r'C:\Users\Tsarev\Desktop\my.py')  #вовращает файл
'my.py'
>>> os.path.splitext(r'C:\Users\Tsarev\Desktop\my.py')  #Вернет arg[1] расширение
('C:\\Users\\Tsarev\\Desktop\\my', '.py')
>>> pathname = r'C:\Users\Tsarev\Desktop\my.py'
>>> os.path.split(pathname) #отделить имя файла от каталога
('C:\\Users\\Tsarev\\Desktop', 'my.py')
>>> pathname.split(os.sep) #разбить путь по символам слеша
['C:', 'Users', 'Tsarev', 'Desktop', 'my.py']
>>> os.sep.join(pathname.split(os.sep))
'C:\\Users\\Tsarev\\Desktop\\my.py'
>>> os.path.join(*pathname.split(os.sep))
'C:Users\\Tsarev\\Desktop\\my.py'
>>> os.path.normpath(r'C:\\Users/Tsarev\Desktop\\my.py') #вернет нормальный путь
'C:\\Users\\Tsarev\\Desktop\\my.py'
>>> os.chdir(r'C:\Users')
>>> os.getcwd()
'C:\\Users'
>>> os.path.abspath('') #пустая строка означает тек. раб. каталог (cwd)
'C:\\Users'
>>> os.path.abspath('Desktop') #расширяет до полного пути к файлу в тек. кат
'C:\\Users\\Desktop'
>>> os.path.abspath(r'Tsarev/Desktop') #частичный путь относительно тек. раб. кат.
'C:\\Users\\Tsarev\\Desktop'
>>> os.path.abspath('.') #расширяетт относительные пути
'C:\\Users'
>>> os.path.abspath('..')
'C:\\'
>>> os.path.abspath(r'C:\Users\Tsarev\Desktop\my.py') #абсолютные пути не изменяются
'C:\\Users\\Tsarev\\Desktop\\my.py'
>>> os.startfile('my.py') #стартует файл
>>> os.stat(r'my.py')
os.stat_result(st_mode=33206, st_ino=3377699720675444, st_dev=3371404606, st_nlink=1, 
               st_uid=0, st_gid=0, st_size=303, st_atime=1529340691, st_mtime=1529343150, st_ctime=1529340691)
>>> for line in os.popen('dir /B *.py'):
	      print(line, end='')	
my.py
