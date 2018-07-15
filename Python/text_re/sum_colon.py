table.txt
---------
1 5 10 2 1.0
2 10 20 4 2.0
3 15 30 8 3
4 20 40 16 4.0
----------

get_sum_from_colon.py
-------------
def get_summ(num_cols, file_name):
	sums = [0] * num_cols	#создать список заполненый нулями
	for line in open(file_name):
		cols = line.split()	#разбить строки
		for i in range(num_cols):
			sums[i] += eval(cols[i])
	return sums
	
if __name__ == '__main__':
	import sys
	print(get_summ(eval(sys.argv[1]), sys.argv[2])) #my.py cols file
--------------------------------------

>python get_sum_from_colom.py 3 table.txt
[10, 50, 100]

--------------------------------------------------------

>>> open('table4.txt', 'w').write('001.1 002.2 003.3\n010.1 020.2 030.3 040.4\n100.1 200.2 300.3')
59
>>> print(open('table4.txt').read())
001.1 002.2 003.3
010.1 020.2 030.3 040.4
100.1 200.2 300.3
>>> sums = {}
>>> for line in open('table4.txt'):
	cols = [float(col) for col in line.split()]
	print(cols)
	for pos, val in enumerate(cols):
		print(cols)
		print('Pos: ', pos)
		print('val: ', val)
		sums[pos] = sums.get(pos, 0.0) + val

		
[1.1, 2.2, 3.3]
[1.1, 2.2, 3.3]
Pos:  0
val:  1.1
[1.1, 2.2, 3.3]
Pos:  1
val:  2.2
[1.1, 2.2, 3.3]
Pos:  2
val:  3.3
[10.1, 20.2, 30.3, 40.4]
[10.1, 20.2, 30.3, 40.4]
Pos:  0
val:  10.1
[10.1, 20.2, 30.3, 40.4]
Pos:  1
val:  20.2
[10.1, 20.2, 30.3, 40.4]
Pos:  2
val:  30.3
[10.1, 20.2, 30.3, 40.4]
Pos:  3
val:  40.4
[100.1, 200.2, 300.3]
[100.1, 200.2, 300.3]
Pos:  0
val:  100.1
[100.1, 200.2, 300.3]
Pos:  1
val:  200.2
[100.1, 200.2, 300.3]
Pos:  2
val:  300.3

>>> for key in sorted(sums):
	print(key, '=', sums[key])

	
0 = 111.3
1 = 222.6
2 = 333.90000000000003
3 = 40.4
>>> sums
{0: 111.3, 1: 222.6, 2: 333.90000000000003, 3: 40.4}
