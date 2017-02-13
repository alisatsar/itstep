'''1 Кредитование

Создать прогшрамму которая посчитает кредит для потребителя по формуле
Month = (Summ * Proc * (1 + Proc)Years) / (12 * ((1 + Proc)Years – 1))
Где:
Month - размер месячной выплаты;
Summ - сумма займа (кредита);
Proc - процент банка, выраженный в долях единицы (т. е. если 20%, то будет 0.2).
Years - количество лет, на которые берется займ.
All - сумма выплат за весь период кредитования.

Вывод должен быть похож на:
	Сколько хотите взять денег: s
	Под какой процент вам их дают: p
	Насколько лет берете: n
	Ваш месячный платеж составит: m
	За весь период вы заплатите: ALL'''

howMoney = float(input("How money you are want take in USD?\n")) #пользователь вводит сумму кредита
percentage = float(input("Which percentage?\n")) #Пользователь вводит процент
years = float(input("To how many years you take credit?\n")) #Пользователь вводит на сколько лет он берет кредит

petcentageInRate = percentage / 100; #процент банка, выраженный в долях единицы

#формула расчета выплаты за месяц
paymentInMonth = (howMoney * petcentageInRate * (1 + petcentageInRate) * years)/ (12 * ((1 + petcentageInRate) * years - 1))

print("Your payment in month:", round(float(paymentInMonth), 4), "USD") #Пользователь вводит месячный платеж

allMonths = years * 12; #Всего месяцев выплачивать

print("The payoff for all the time:", round(float(allMonths * paymentInMonth), 4), "USD\n\n") #Выплата за все время

input("Press Enter for continue...\n")