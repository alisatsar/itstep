>>> from io import StringIO
>>> buff = StringIO()
>>> buff.write('spam\n')
5
>>> buff.write('eggs\n')
5
>>> buff.getvalue()
'spam\neggs\n'
>>> buff = StringIO('ham\nspam\n')
>>> buff.readline()
'ham\n'
>>> buff.readline()
'spam\n'
>>> buff.readline()
''
>>> 
