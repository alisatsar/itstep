'''(.*) 
означает любой символ (.), повторяющийся ноль или более раз (*).'''
'''[ \t]*
ноль и более символов пробела или табуляции'''
'''[ \t]+
пропускает один и более символов пробела и табуляции'''
'''[Ww]
может начинаться или с W или w'''
'''\s* 
в следующем примере обозначают ноль или более пробельных
символов (задан класс символов);'''
'''\s+ 
– означают один или более таких символов;'''
'''/? 
соответствует необязательному символу слэша;'''
'''[a-z] 
любому строчному символу (задан диапазон);'''


>>> text1 = 'hello spam...World'
>>> text2 = 'hello spam...other'
>>> import re
>>> match_object = re.match('hello(.*)World', text2)
>>> print(match_object)
None
>>> match_object = re.match('hello(.*)World', text1)
>>> print(match_object)
<_sre.SRE_Match object; span=(0, 18), match='hello spam...World'>
>>> match_object.group(1)   #вызов group(1) возвращает первый, самый левый фрагмент испытуемой строки,
#совпавший с частью шаблона, заключенной в круглые скобки (с нашей конструкцией (.*))
' spam...'

>>> compile_reg = re.compile('hello(.*)World')    #Компилированный шаблон, для ускорения скорости работы
>>> match_obj = compile_reg.match(text1)
>>> match_obj.group(1)
' spam...'


>>> pat = re.compile('[ \t]*hello[ \t]+(.*)[Ww]orld')
>>> line = ' hello spamworld'
>>> match_obj = pat.match(line)
>>> match_obj.group(1)
'spam'

>>> import re
>>> re.split('--', 'aaa--bbb-ccc')
['aaa', 'bbb-ccc']
>>> re.split('--', 'aaa--bbb--ccc')
['aaa', 'bbb', 'ccc']
>>> re.sub('--', '...', 'aaa--bbb--ccc')
'aaa...bbb...ccc'
>>> re.split('--|==', 'aaa--bbb==ccc')
['aaa', 'bbb', 'ccc']
>>> re.sub('--|==', '...', 'aaa--bbb==ccc')
'aaa...bbb...ccc'
>>> re.split('[-=]', 'aaa-bbb=ccc')
['aaa', 'bbb', 'ccc']
>>> re.split('(--)|(==)', 'aaa--bbb==ccc')
['aaa', '--', None, 'bbb', None, '==', 'ccc']
>>> re.split('(?:--)|(?:==)', 'aaa--bbb==ccc')
['aaa', 'bbb', 'ccc']
>>> 'spam/ham/eggs'.split('/')
['spam', 'ham', 'eggs']
>>> re.match('(.*)/(.*)/(.*)', 'spam/ham/eggs').group()
'spam/ham/eggs'
>>> re.match('(.*)/(.*)/(.*)', 'spam/ham/eggs').groups()
('spam', 'ham', 'eggs')
>>> re.match('<(.*)>/<(.*)>/<(.*)>', '<spam>/<ham>/<eggs>').groups()
('spam', 'ham', 'eggs')
>>> re.match('\s*<(.*)>/?<(.*)>/?<(.*)>', '<spam>/<ham>/<eggs>').groups()
('spam', 'ham', 'eggs')
>>> 'Hello pattern world!'.split()
['Hello', 'pattern', 'world!']
>>> re.match('Hello\s*([a-z]*)\s+(.*?)\s*!', 'Hellopattern world !').groups()
('pattern', 'world')
>>> 

>>> p = re.compile('A(.)B(.)C(.)')
>>> m = p.match('A0B1C2')
>>> print(m.group(1), m.group(2), m.group(3))
0 1 2
>>> print(m.group(0))
A0B1C2

