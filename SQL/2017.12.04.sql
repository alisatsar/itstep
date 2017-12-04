CREATE TABLE PhoneCalls(
	DateCalls date NOT NULL,
	PhoneNumber int NOT NULL,
	Prefix int NOT NULL
)ON [PRIMARY]
GO

CREATE TABLE PhoneNumber(
	PhoneNumber int NOT NULL,
	Prefix int NOT NULL,
	UserId int NOT NULL,
	TariffName nvarchar(50) NOT NULL
) ON [PRIMARY]
GO

CREATE TABLE Tariff(
	TariffName nvarchar(50) NOT NULL,
	PriceForOneMinute decimal(18, 0) NOT NULL,
	CountFreeMinute int NOT NULL,
	CountFreeMegabyte int NOT NULL
) ON [PRIMARY]
GO

CREATE TABLE UserData(
	UserId int IDENTITY(1,1) NOT NULL,
	FirstName nvarchar(50) NULL,
	SecondName nvarchar(50) NULL,
 CONSTRAINT [PK_UserData_UserId] PRIMARY KEY CLUSTERED 
(
	[UserId] ASC
)WITH (PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON) ON [PRIMARY]
) ON [PRIMARY]
GO

ALTER TABLE PhoneNumber
WITH CHECK ADD CONSTRAINT FK_PhoneNumber_TariffName FOREIGN KEY(TariffName)
REFERENCES Tariff (TariffName)
ON UPDATE CASCADE
ON DELETE CASCADE
GO

ALTER TABLE PhoneNumber
WITH CHECK ADD CONSTRAINT FK_PhoneNumber_UserId FOREIGN KEY(UserId)
REFERENCES UserData (UserId)
ON UPDATE CASCADE
ON DELETE CASCADE
GO

ALTER TABLE PhoneCalls
ALTER COLUMN Prefix int NOT NULL
GO

ALTER TABLE PhoneCalls
WITH CHECK ADD CONSTRAINT FK_PhoneCalls_Prefix FOREIGN KEY(Prefix)
REFERENCES PhoneNumber (Prefix)
ON UPDATE CASCADE
ON DELETE CASCADE
GO

alter table PhoneNumber
add constraint EX_PhoneNumber_PhoneNumber_Prefix primary key (PhoneNumber, Prefix)
GO

ALTER TABLE Tariff
Add Constraint PK_Tariff_TariffName PRIMARY KEY Clustered (TariffName)
GO

alter table PhoneCalls
add constraint EX_PhoneCalls_DateCalls_PhoneNumber_Prefix 
primary key (DateCalls, PhoneNumber, Prefix)
GO

INSERT INTO UserData (FirstName, SecondName) VALUES
	('Oleg', 'Shysharev'),
	('Margarita', 'Almaznat'),
	('Sergey', 'Root'),
	('Anna', 'Kip'),
	('Marta', 'Anisimova'),
	('Vladimir', 'Solov'),
	('Evgeniy', 'Orlov'),
	('Aleksandr', 'Kirov'),
	('Maria', 'Arhenko'),
	('Elena', 'Borisova');
	
GO
Create View VwPhoneNumbers
As
