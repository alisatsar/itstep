import re
import os

os.chdir(r'D:\test\2\2.1')

result_file = open(r'city_settings.xml', 'w')

with open(r'../city_settings.xml', encoding='utf-8') as file:
	for line in file:
		line = re.sub(r' \bamount="(.*)"', '', line)	
		result_file.write(line)
		
result_file.close()
input("press any key to continue...")
