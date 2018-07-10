nano hello-out.py
--------
print(‘Hello shell world’)
--------

nano hello-in.py
--------
inp = input()
open(‘hello-in.txt’, ‘w’).write(‘Hello ‘ + inp + ‘\n’)
--------

>>> from subprocess import Popen, PIPE, call #импорт модуля
>>> x = call('python hello-out.py')
>>> x
2
>>> pipe = Popen('python hello-out.py', stdout=PIPE) #объект с открытым каналом sdtout
>>> pipe.communicate()[0] #return tuple stdout_data (becouse 0 element)
b'Hello shell world\r\n'
>>> pipe.returncode #код завершения
0

>>> pipe = Popen('python hello-out.py', stdout=PIPE)
>>> pipe.stdout.read()
b'Hello shell world\r\n'
>>> pipe.wait() #ожидает завершения дочернего процесса, устанавливает и возвращает код завершения
0

>>> pipe = Popen('python hello-in.py', stdin=PIPE)  #объект с открытым каналом sdtin
>>> pipe.stdin.write(b'Pokey\n') #записывает sdtin
6
>>> pipe.stdin.close() #закрываем sdtin
>>> pipe.wait()
0
>>> open('input.txt').read()
'Hello Pokey\n'
>>> 
