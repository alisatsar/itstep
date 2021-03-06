USE [PhoneNumbers]
GO
/****** Object:  StoredProcedure [dbo].[InsertPhoneNumber]    Script Date: 13.12.2017 1:07:01 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
ALTER PROCEDURE [dbo].[InsertPhoneNumber]
As
declare @UserId int
declare @TariffName nvarchar(50)
declare @PhoneNumber int = 1000000
while (select count(PhoneNumber) from PhoneNumber) < 100000
Begin
	set @PhoneNumber = @PhoneNumber + 1
	select top 1 @UserId = UserId from UserData order by NEWID()
	select top 1 @TariffName = TariffName from Tariff order by NEWID()
	insert into PhoneNumber values
	(@PhoneNumber, '44', @UserId, @TariffName)	
end	 
