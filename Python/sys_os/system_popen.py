'C:\\Users\\Tsarev\\Desktop\\my.py'
>>> os.system('dir /B')
   
0

>>> os.chdir(r'C:\Users\Tsarev\Desktop')
	      
>>> open(r'my.py').read()
	      
"def more(text, numlines=15):\n\tlines = text.splitlines()\n\twhile lines:\n\t\tchunk = lines[:numlines]\n\t\tlines = lines[numlines:]\n\t\tfor line in chunk:\n\t\t\tprint(line)\n\t\tif lines and input('MORE?') not in ['y', 'Y']: break\n\t\t\nif __name__ == '__main__':\n\timport sys\n\tmore(open(sys.argv[1]).read(), 10)"
>>> text = os.popen('type my.py').read()
	      
>>> text
	      
"def more(text, numlines=15):\n\tlines = text.splitlines()\n\twhile lines:\n\t\tchunk = lines[:numlines]\n\t\tlines = lines[numlines:]\n\t\tfor line in chunk:\n\t\t\tprint(line)\n\t\tif lines and input('MORE?') not in ['y', 'Y']: break\n\t\t\nif __name__ == '__main__':\n\timport sys\n\tmore(open(sys.argv[1]).read(), 10)"

>>> os.system(r'cd /D D:\test')
	      
0
>>> os.getcwd()
	      
'C:\\Users\\Tsarev\\Desktop'
>>> os.chdir(r'D:\test')
	      
>>> os.getcwd()
	      
'D:\\test'
>>> listing = os.popen(r'dir /2.1').readlines()
	      
>>> listing
	      
[]
>>> listing = os.popen(r'dir /B').readlines()
	      
>>> listing
	      
['1\n', '2\n', '3\n', '4\n', '5 ‚ҐабвЄ\xa0 ¤Ё\xa0«®Ј\xa0\n', 'Є\xa0Є зв® ¤Ґ«\xa0«\xa0.txt\n']

>>>os.system(r'python 2_1_delete_amount.py\n')
2
>>> output = os.popen(r'python 2_1_delete_amount.py\n').read()
	      
>>> output
	      
''
