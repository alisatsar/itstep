import re, os, io

os.chdir(r'D:\test\3\3.1')

#read data from file data.txt about dialog
data_file = open(r'../data.txt', 'r')
print(data_file)
line = data_file.readline()
print(line)
pattern = re.compile(r'"(.*?)"')
dialog_name = pattern.findall(line)[0]
print(pattern.findall(line))
line = data_file.readline()
deltaX = int(pattern.findall(line)[0])
line = data_file.readline()
deltaY = int(pattern.findall(line)[0])
data_file.close()

dialog_is_find = False

pattern_left = re.compile(r'left="(.*?)"')
pattern_top = re.compile(r'top="(.*?)"')

result_file = open(r'city.xml', 'w')

with io.open(r'../city.xml', encoding='utf-8') as file:
	for line in file:
		match = re.search(dialog_name, line)
		if match and dialog_is_find == False:
			dialog_is_find = True
		elif match and dialog_is_find:
			dialog_is_find = False
		if dialog_is_find:		
			match = re.search(r'<Control(.*)>', line)
			if match:	
				left = pattern_left.findall(str(match.group()))
				print(str(match.group()))		
				if left:
					print(left[0])
					s = r'left="' + str(int(left[0]) + deltaX) + '"'
					line = re.sub(r'left="(.*?)"', s, line)
				top = pattern_top.findall(str(match.group()))
				if top:
					s = r'top="' + str(int(top[0]) + deltaY) + '"'
					line = re.sub(r'top="(.*?)"', s, line)
				print(line)
		result_file.write(line)
result_file.close()

input('Press any to continue...')
