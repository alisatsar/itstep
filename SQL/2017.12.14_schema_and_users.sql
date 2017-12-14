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

----------перемещение таблицы

ALTER SCHEMA dbo TRANSFER Sellers.Sellers;
GO

----------------------------
CREATE LOGIN Alisa2 
    WITH PASSWORD = '123';
USE alisa;
CREATE USER A2 FOR LOGIN Alisa2;
GO 

CREATE ROLE Sel AUTHORIZATION A2;  
GO  

GRANT SELECT ON PhoneCalls
    TO A2;

--дать права пользователю A1 на передачу другому пользователю insert

GRANT INSERT ON PhoneCalls
    TO A1
	With grant option;

--дать права пользователю A1 на insert

GRANT INSERT ON PhoneCalls
    TO A2
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


