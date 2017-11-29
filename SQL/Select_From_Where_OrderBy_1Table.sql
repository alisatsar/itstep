--Добавить столбец
alter Table Drug
ADD b int identity(1, 1)
go

--добавляем первичный ключ
Alter Table Drug
ADD CONSTRAINT PK_Drug_PrimaryKey PRIMARY KEY CLUSTERED (b)
GO

--Выбираем отдельные столбцы
SELECT Cost, Name 
From Drug
ORDER BY Cost --сортировка по цене

--сортировка по дате в обратном порядке
SELECT Cost, Name 
From Drug
--где DateExpiryDate больше 2018 01 01
WHERE DateExpiryDate > '20180101' 
ORDER BY ProductionDate DESC 

--сортировка по дате в обратном порядке
SELECT Cost, Name 
From Drug
--промежуток
WHERE DateExpiryDate BETWEEN '20160101' AND '20180101'
ORDER BY ProductionDate DESC 
