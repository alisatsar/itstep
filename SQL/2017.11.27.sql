Insert into Drug (Name, Cost, ProductionDate, DateExpiryDate) values
('Alisa', '20', '2017-11-11', '2017-11-11')

delete from Drug where Name='Alisa'

select *from Drug

Insert into Drug (Name, Cost, ProductionDate, DateExpiryDate) values
('Alisa', '20', '2017-11-11', '2017-11-11')

select *from Drug

update Drug set Name='Asperin' where Cost='20'

Insert into Drug (Name, Cost, ProductionDate, DateExpiryDate) values
('Spazmalgon', '3', '2015-10-11', '2018-01-11')

Insert into DrugStore (City, Street, House) values
('Mogilev', 'Sovetskaya', '33')

select *from DrugStore

Create Table Pharmacist(
	IdPharmacist int IDENTITY(1,1),
	FirstName nvarchar(50) NOT NULL,
	SecondNAme nvarchar(50) NOT NULL
)ON [PRIMARY]
GO

ALTER TABLE AllDrugStores
WITH CHECK ADD CONSTRAINT FK_Drug_IdDrug FOREIGN KEY(IdDrug)
REFERENCES Drug (DrugId)
ON UPDATE CASCADE
ON DELETE CASCADE
GO

ALTER TABLE AllDrugStores
WITH CHECK ADD CONSTRAINT FK_Drug_DrugId FOREIGN KEY(IdDrugStore)
REFERENCES DrugStore (IdDrugStore)
ON UPDATE CASCADE
ON DELETE CASCADE
GO

Insert into Pharmacist (FirstName, SecondNAme) values
('Alisa', 'Tsarova')

select *from Pharmacist

ALTER TABLE Pharmacist
ADD CONSTRAINT PK_Pharmacist_IdPharmacist PRIMARY KEY CLUSTERED (IdPharmacist)
GO

select *from Pharmacist

ALTER TABLE DrugStore
ADD IdPharmacist int
GO 

ALTER TABLE DrugStore
ALTER COLUMN IdPharmacist int NOT NULL
GO

select *from DrugStore

update DrugStore set IdPharmacist='1' where City='Mogilev'

ALTER TABLE DrugStore
WITH CHECK ADD CONSTRAINT FK_Pharmacist_IdPharmacist FOREIGN KEY(IdPharmacist)
REFERENCES Pharmacist (IdPharmacist)
ON UPDATE CASCADE
ON DELETE CASCADE
GO
