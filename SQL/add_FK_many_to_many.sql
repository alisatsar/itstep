SET QUOTED_IDENTIFIER ON
GO

CREATE TABLE AllDrugStores(	
	IdDrugStore int NULL,
	IdDrug int NULL
) ON [PRIMARY]
GO

ALTER TABLE AllDrugStores
ALTER COLUMN IdDrugStore int NOT NULL
GO

ALTER TABLE AllDrugStores
ALTER COLUMN IdDrug int NOT NULL
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