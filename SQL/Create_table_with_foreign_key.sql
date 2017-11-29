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
