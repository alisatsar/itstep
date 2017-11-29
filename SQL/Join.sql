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
