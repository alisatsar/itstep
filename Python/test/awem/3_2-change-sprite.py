import re

#read data from file data.txt about dialog
data_file = open('../data_3_2.txt', 'r')
line = data_file.readline()
pattern = re.compile(r'"(.*?)"')
sprite_name = pattern.findall(line)[0]
line = data_file.readline()
deltaX = int(pattern.findall(line)[0])
line = data_file.readline()
deltaY = int(pattern.findall(line)[0])
line = data_file.readline()
deltaW = int(pattern.findall(line)[0])
line = data_file.readline()
deltaH = int(pattern.findall(line)[0])
data_file.close()

pattern_left = re.compile(r'left="(.*?)"')
pattern_top = re.compile(r'top="(.*?)"')
pattern_width = re.compile(r'width="(.*?)"')
pattern_height = re.compile(r'height="(.*?)"')

result_file = open('city.xml', 'w')
for line in open('../city.xml', 'r'):
	match = re.search(sprite_name, line)
	if match:		
		left = pattern_left.findall(line)
		if left:
			s = r'left="' + str(int(left[0]) + deltaX) + '"'
			line = pattern_left.sub(s, line)	
		top = pattern_top.findall(line)		
		if top:
			s = r'top="' + str(int(top[0]) + deltaY) + '"'
			line = pattern_top.sub(s, line)
		width = pattern_width.findall(line)
		if width:
			s = r'width="' + str(int(top[0]) + deltaW) + '"'
			line = pattern_width.sub(s, line)
		else:
			s = r' width="' + str(100 + deltaW) + '"/>'
			line = re.sub("/>", s, line)
		height = pattern_height.findall(line)
		if height:
			s = r'height="' + str(int(top[0]) + deltaH) + '"'
			line = pattern_height.sub(s, line)
		else:
			s = r' height="' + str(200 + deltaH) + '"/>'
			line = re.sub("/>", s, line)			
	result_file.write(line)
result_file.close()
