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
	
ALTER TABLE PhoneCalls
   ADD CONSTRAINT FK_PhoneCalls_PhoneNumberAndPrefix
   FOREIGN KEY(PhoneNumber, Prefix)
   REFERENCES PhoneNumber(PhoneNumber, Prefix)


INSERT INTO Tariff(TariffName, PriceForOneMinute, CountFreeMegabyte,CountFreeMinute) VALUES
	('Plus500', '10', '500', '24'),
	('Plus100', '5', '100', '12'),
	('Deti', '1', '10', '50'),
	('Another', '2', '1000', '50')

Insert Into PhoneNumber(PhoneNumber, Prefix, UserId, TariffName) values
('2963964', '44', '1', 'Another'),
('1125052', '24', '2', 'Another'),
('5525525', '24', '2', 'Deti'),
('5525525', '44', '3', 'Plus100'),
('7745454', '44', '4', 'Plus500'),
('4565465', '44', '5', 'Plus100'),
('4276337', '44', '6', 'Deti'),
('7357735', '44', '7', 'Plus500'),
('9396463', '44', '8', 'Plus500'),
('4576321', '44', '9', 'Deti'),
('3753543', '44', '10', 'Plus100')

Insert Into PhoneCalls(DateCalls, PhoneNumber, Prefix) values
('2017-11-01', '1125052', '24'),
('2017-11-27', '5525525', '24'),
('2017-11-30', '5525525', '44'),
('2017-10-25', '2963964', '44'),
('2017-11-13', '1125052', '24'),
('2017-11-18', '5525525', '24'),
('2017-11-30', '7357735', '44'),
('2017-10-04', '9396463', '44'),
('2017-11-01', '9396463', '44'),
('2017-11-27', '4576321', '44'),
('2017-11-30', '4576321', '44'),
('2017-10-25', '3753543', '44'),
('2017-11-13', '3753543', '44'),
('2017-10-18', '5525525', '24'),
('2017-10-30', '7357735', '44'),
('2017-11-05', '1125052', '24'),
('2017-11-05', '5525525', '24'),
('2017-11-05', '5525525', '44'),
('2017-12-05', '2963964', '44')


select *from PhoneCalls

GO
Create View VwPhoneCalls
As
Select PhoneCalls.DateCalls, 
	PhoneCalls.PhoneNumber,
	PhoneCalls.Prefix,	
	Tariff.TariffName,
	Tariff.PriceForOneMinute
From PhoneCalls,PhoneNumber
JOIN Tariff ON PhoneNumber.TariffName = Tariff.TariffName
JOIN UserData ON PhoneNumber.UserId = UserData.UserId
GO

select *from PhoneCalls

go
select *from dbo.Get_Number_prefix('44')

select *from PhoneNumber

select dbo.GetUser('Deti', '5525525')

CREATE TABLE PhoneCalls(
	DateCallsBegin datetime NOT NULL,
	DateCallsEnd datetime NOT NULL,
	PhoneNumber int NOT NULL,
	Prefix int NOT NULL
)ON [PRIMARY]
GO

ALTER TABLE PhoneCalls
ADD COLUMN `id_user_5` text NOT NULL default '' AFTER `hometask`;

alter table PhoneCalls
add constraint EX_PhoneCalls_DateCalls_PhoneNumber_Prefix 
primary key (DateCallsBegin, DateCallsEnd,  PhoneNumber, Prefix)
GO

ALTER TABLE PhoneCalls
   ADD CONSTRAINT FK_PhoneCalls_PhoneNumberAndPrefix
   FOREIGN KEY(PhoneNumber, Prefix)
   REFERENCES PhoneNumber(PhoneNumber, Prefix)

Insert Into PhoneCalls(DateCallsBegin, DateCallsEnd, PhoneNumber, Prefix) values
('20171101 00:02:00 AM', '20171101 00:03:45 AM', '1125052', '24'),
('20171130 11:45:07 PM', '20171130 11:46:10 PM', '5525525', '44'),
('20171127 10:45:07 AM', '20171127 10:47:10 AM', '5525525', '24'),
('20171025 02:25:25 AM', '20171025 02:28:45 AM', '2963964', '44'),
('20171113 06:39:58 PM', '20171025 06:55:45 PM', '1125052', '24'),
('20171118 01:55:33 AM', '20171025 02:05:45 AM', '5525525', '24'),
('20171130 03:44:18 PM', '20171025 04:05:45 PM', '7357735', '44'),
('20171004 07:05:23 PM', '20171025 08:14:45 PM', '9396463', '44')

TRUNCATE TABLE PhoneCalls

Create Table FailureInput(
TableName nvarchar(50), not null,
TableLog nvarchar(50), not null,
DateWrite datetime, not null
)ON [PRIMARY]
GO

alter table FailureInput
add constraint EX_FailureInput_TableName_TableLog_DateWrite
primary key (TableName, TableLog, DateWrite)
GO

select *from FailureInput
