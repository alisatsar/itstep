>>>import subprocess
	      
>>> subprocess.call('python 2_1_delete_amount.py') # напоминает os.system()
	      
0
>>> subprocess.call('cmd /C "type 2_1_delete_amount.py"') # встроенная команда
	      
0
>>> subprocess.call('type 2_1_delete_amount.py', shell=True) #платформозависимая особенность
	      
0
>>> pipe = subprocess.Popen('python 2_1_delete_amount.py', stdout=subprocess.PIPE)
	      
>>> pipe.communicate()
	      
(b'press any key to continue...', None) #input/out 
>>> pipe.returncode
	      
120

>>> import os
>>> os.getcwd()
'C:\\Users\\Tsarev\\AppData\\Local\\Programs\\Python\\Python36'
>>> os.chdir(r'C:\Users\Tsarev\Desktop')
>>> pipe = subprocess.Popen('python my.py', stdout=subprocess.PIPE)
>>> pipe.stdout.read()
b''
>>> pipe.wait()
120
>>> from subprocess import Popen, PIPE
>>> Popen('python my.py', stdout=PIPE).communicate()[0]
b''
