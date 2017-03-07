##4. Дано действительное положительное число a и целоe число n. Вычислите an.
# Решение оформите в виде функции power(a, n). Стандартной функцией возведения в степень пользоваться нельзя.

def power(a, n):
    result = a ** n
    return result

a = float(input("Enter a: "))
n = int(input("Enter degree: "))
print("a to the power n = ", power(a, n))
