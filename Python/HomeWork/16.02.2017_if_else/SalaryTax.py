#1.Запросить у пользователя зарплату
#Если зарплата от меньше 100, налог - 3 %
#Если зарплата от 100 до 600, налог - 10 %
#Если зарплата от 600 до 2000, налог - 18 %
#Если запрата более 2000, налог - 22 %
#Вывести 'чистую зарплату', налог, и 'глязную зарплату'

salary = int(input("Please, enter your salary in month:")) #Пользователь вводит свою зарплату

if salary < 100:
    nalogPercentage = 3    #%налога в зависимости от суммы зарплаты
elif 100 <= salary < 600:
    nalogPercentage = 10
elif 600 <= salary < 2000:
    nalogPercentage = 18
else:
    nalogPercentage = 22

tax = salary * nalogPercentage / 100 #%вычисляется сумма налога

print("Your White salary = ", salary - tax, "\nYour tax =", tax, "\nYour Black salary = ", salary)
