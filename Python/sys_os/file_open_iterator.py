>>> file = open('data.txt')
>>> for line in file:
	print(line, end='')

	
hello my world
 how are you!
 this is insane people
 i hate them
>>> for line in open('data.txt'):
	print(line, end='')

	
hello my world
 how are you!
 this is insane people
 i hate them
>>> for line in open('data.txt'):
	print(line)

	
hello my world

 how are you!

 this is insane people

 i hate them
 
 
 -------------------------

>>> file = open('data.txt')
>>> file.__next__()
'hello my world\n'
>>> file.__next__()
' how are you!\n'
>>> file.__next__()
' this is insane people\n'
>>> file.__next__()
' i hate them\n'
>>> file.__next__()
Traceback (most recent call last):
  File "<pyshell#16>", line 1, in <module>
    file.__next__()
StopIteration

-------------------------------

>>> open('data.txt').readlines()
['hello my world\n', ' how are you!\n', ' this is insane people\n', ' i hate them\n']
>>> list(open('data.txt'))
['hello my world\n', ' how are you!\n', ' this is insane people\n', ' i hate them\n']
>>> lines = [line.rstrip() for line in open('data.txt')]
>>> lines
['hello my world', ' how are you!', ' this is insane people', ' i hate them']
>>> lines = [line.upper() for line in open('data.txt')]
>>> lines
['HELLO MY WORLD\n', ' HOW ARE YOU!\n', ' THIS IS INSANE PEOPLE\n', ' I HATE THEM\n']
>>> lines = [line.upper().rstrip() for line in open('data.txt')]
>>> lines
['HELLO MY WORLD', ' HOW ARE YOU!', ' THIS IS INSANE PEOPLE', ' I HATE THEM']
>>> list(map(str.split, open('data.txt')))
[['hello', 'my', 'world'], ['how', 'are', 'you!'], ['this', 'is', 'insane', 'people'], ['i', 'hate', 'them']]
>>> line = 'hello my world\n'
>>> line in open('data.txt')
True
