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
