>>>import subprocess
	      
>>> subprocess.call('python 2_1_delete_amount.py') # напоминает os.system()
	      
0
>>> subprocess.call('cmd /C "type 2_1_delete_amount.py"') # встроенная команда
	      
0
>>> subprocess.call('type 2_1_delete_amount.py', shell=True)
	      
0
>>> pipe = subprocess.Popen('python 2_1_delete_amount.py', stdout=subprocess.PIPE)
	      
>>> pipe.communicate()
	      
(b'press any key to continue...', None)
>>> pipe.returncode
	      
120
>>> 
