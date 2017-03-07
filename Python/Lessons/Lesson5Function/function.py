def foo(x,y):
    res = x ** y
    return res

#print(foo())

def max3(a, b, c):
    return max(max(a,b),c)
print("max value: ")
print(max3(3, 5, 6))

def f(a, b, c):
    min = a * b
    max = b * c
    mix = a * c
    return max, min, mix

print(f(1, 3, 5))

def foo1():
    global a
    a = 1
    print(a)

a = 0
foo1()
print(a)
