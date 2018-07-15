'''(.*) 
означает любой символ (.), повторяющийся ноль или более раз (*).'''
'''[ \t]*
ноль и более символов пробела или табуляции'''
'''[ \t]+
пропускает один и более символов пробела и табуляции'''
'''[Ww]
может начинаться или с W или w'''

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
