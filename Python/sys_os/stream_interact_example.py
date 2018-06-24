def interact():
	print('Hello stream world')
	while True:
		try:
			reply = input('Enter a number>')
		except EOFError:
			break
		else:
			num = int(reply)
			print("number %d ^2 is %d" % (num, num ** 2))
	print('You press Ctrl+Z(Windows) or Ctrl+D(Unix)')
		
if __name__== '__main__':
	interact() #если выполняется, а не импортируется
