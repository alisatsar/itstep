select * from AllDrugStores

select * from Pharmacist

select * from DrugStore

select * from Drug

insert into AllDrugStores(IdDrugStore, IdDrug) values
('5', '2')

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

--выборка из несколька таблица с помощью join
SELECT IdDrug, AllDrugStores.IdDrugStore, Drug.Name AS DrugName, DrugStore.City
FROM AllDrugStores
JOIN Drug ON AllDrugStores.IdDrug = Drug.DrugId
JOIN DrugStore ON AllDrugStores.IdDrugStore = DrugStore.IdDrugStore
GO

SELECT DS.City, DS.Street, DS.House, DS.IdPharmacist, Pharmacist.FirstName
FROM DrugStore AS DS
JOIN Pharmacist ON DS.IdPharmacist = Pharmacist.IdPharmacist
GO

--выборка из несколька таблица с помощью left join для NULL В остальных столбцах
SELECT IdDrug, AllDrugStores.IdDrugStore, Drug.Name AS DrugName, DrugStore.City
FROM AllDrugStores 
LEFT JOIN Drug ON AllDrugStores.IdDrug = Drug.DrugId
LEFT JOIN DrugStore ON AllDrugStores.IdDrugStore = DrugStore.IdDrugStore
WHERE Drug.DateExpiryDate > '20180101'
GO

--перемножение
SELECT DS.City, DS.Street, DS.House, DS.IdPharmacist, Pharmacist.FirstName
FROM DrugStore AS DS
CROSS JOIN Pharmacist
GO

--выводит все записи из двух таблиц
SELECT DS.City, DS.Street, DS.House, DS.IdPharmacist, Pharmacist.FirstName
FROM DrugStore AS DS
CROSS JOIN Pharmacist
GO

--создаем таблицу сразу с внешним ключем
CREATE TABLE Salary (
IdPharmacist int NOT NULL REFERENCES Pharmacist (IdPharmacist)
ON DELETE CASCADE ON UPDATE CASCADE,
Salary int NOT NULL,
StandartHours int NULL 
)
GO 

ALTER TABLE Salary
ADD CONSTRAINT DF_Salary_IdPharmacist_Unique UNIQUE (IdPharmacist)
GO

--Группировка и конконтенация
SELECT ds.City + ' ' + ds.Street,
ph.FirstName + ' ' + ph.SecondNAme, COUNT(s.Salary) as Salary
FROM AllDrugStores allDS
JOIN DrugStore ds ON allDS.IdDrugStore = ds.IdDrugStore
JOIN Pharmacist ph ON ds.IdPharmacist = ph.IdPharmacist
LEFT JOIN Salary s ON ph.IdPharmacist = s.IdPharmacist
GROUP BY ds.City, ds.Street, ph.FirstName, ph.SecondNAme
HAVING ds.Street = 'Lenina'--фильтрация после группировки
GO
