import re, os

os.chdir(r'D:\test\2\2.3')

result_file = open(r'city_settings.xml', 'w')

with open(r'../city_settings.xml', encoding='utf-8') as file:
	for line in file:
		match = re.search(r'\btype="3" amount="(.*)"', line)
		if match:
			value = re.split('" ', str(match.group(1)), flags=re.IGNORECASE)
			s = 'type="' + str(value[0])
			s += '" height="3"'
			if(len(value) == 2):
				s += " " + value[1] + '"'		
			line = re.sub(r'\btype="3" amount="(.*)"', s, line)
		result_file.write(line)
result_file.close()
input("press any key to continue...")
