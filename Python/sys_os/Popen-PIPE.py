nano hello-out.py
--------
print(‘Hello shell world’)
--------

nano hello-in.py
--------
inp = input()
open(‘hello-in.txt’, ‘w’).write(‘Hello ‘ + inp + ‘\n’)
--------

>>> from subprocess import Popen, PIPE, call  #импорт модуля
>>> x = call('python hello-out.py')
>>> x
2
>>> pipe = Popen('python hello-out.py', stdout=PIPE)  #объект с открытым каналом sdtout
>>> pipe.communicate()[0] #return tuple stdout_data
b'Hello shell world\r\n'
>>> pipe.returncode   #код завершения
0

>>> pipe = Popen('python hello-out.py', stdout=PIPE)
>>> pipe.stdout.read()
b'Hello shell world\r\n'
>>> pipe.wait()   #ожидает завершения дочернего процесса, устанавливает и возвращает код завершения
0

>>> pipe = Popen('python hello-in.py', stdin=PIPE)    #объект с открытым каналом sdtin
>>> pipe.stdin.write(b'Pokey\n')  #записывает sdtin
6
>>> pipe.stdin.close()  #закрываем sdtin
>>> pipe.wait()
0
>>> open('input.txt').read()
'Hello Pokey\n'
>>> 

---------------------------------------------------------------------------------
nano reader.py
-------
print('Got this: "%s"' % input())
import sys
data = sys.stdin.readline()[:-1]
print('The meaning of life is', data, int(data) * 2)
-------
>>> from subprocess import Popen, PIPE
>>> pipe = Popen('python reader.py', stdin=PIPE, stdout=PIPE)
>>> pipe.stdin.write(b'Lumberjack\n')
11
>>> pipe.stdin.write(b'12\n')
3
>>> pipe.stdin.close()
>>> output = pipe.stdout.read()
>>> pipe.wait()
0
>>> output
b'Got this: "Lumberjack"\r\nThe meaning of life is 12 24\r\n'

nano writer.py
-------
print("Help! Help! I'm beign repressed!")
print(42)
-------
python writer.py | python reader.py

Got this: “Help! Help! I’m being repressed!”
The meaning of life is 42 84

C:\...\PP4E\System\Streams> python
>>> from subprocess import Popen, PIPE
>>> p1 = Popen(‘python writer.py’, stdout=PIPE)
>>> p2 = Popen(‘python reader.py’, stdin=p1.stdout, stdout=PIPE)
>>> output = p2.communicate()[0]
>>> output
b’Got this: “Help! Help! I\’m being repressed!”\r\nThe meaning of life is 42 84\r\n’
>>> p2.returncode
0

>>> import os
>>> p1 = os.popen(‘python writer.py’, ‘r’)
>>> p2 = os.popen(‘python reader.py’, ‘w’)
>>> p2.write( p1.read() )
36
>>> X = p2.close()
Got this: “Help! Help! I’m being repressed!”
The meaning of life is 42 84
>>> print(X)
None
