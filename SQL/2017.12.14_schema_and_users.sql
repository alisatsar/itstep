CREATE LOGIN Alisa 
    WITH PASSWORD = '123';
USE alisa;
CREATE USER A1 FOR LOGIN Alisa;
GO 

CREATE SCHEMA Sellers
GO
CREATE TABLE Sellers.Sellers (
    SellerId int IDENTITY (1,1),
    FirstName nvarchar(50) NOT NULL,
    SecondName nvarchar(50) NOT NULL);

GRANT SELECT TO A1;
DENY UPDATE TO A1;

exec AddNewSeller Marya, Ivanova

select *from Sellers.Sellers

---------------------------------------------

CREATE PROCEDURE AddNewSeller
(@FirstName nvarchar(50),
 @SecondName nvarchar(50)) 	
AS
BEGIN
	INSERT INTO Sellers.Sellers (Sellers.Sellers.FirstName, Sellers.Sellers.SecondName) values
	(@FirstName, @SecondName)
END
GO
