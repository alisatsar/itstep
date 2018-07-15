import re, os

os.chdir(r'D:\test\2\2.4')

result_file = open(r'city_settings.xml', 'w')

with open(r'../city_settings.xml', encoding='utf-8') as file:
	for line in file:
		match = re.search(r'\btype="([0-9])"', line)
		if match:		
			value = int(match.group(1))		
			value *= 2
			s = 'type="' + str(value) + '"'
			line = re.sub(r'\btype="(\d)"', s, line)		
		result_file.write(line)
result_file.close()
input("press any key to continue...")
