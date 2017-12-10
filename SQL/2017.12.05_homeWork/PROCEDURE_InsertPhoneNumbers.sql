CREATE PROCEDURE InsertPhoneNumbers (
@PhoneNumber int,
@Prefix int,
@UserId int,
@TariffName nvarchar(50))
As 
begin Try
	insert into PhoneNumber values (@PhoneNumber, @Prefix, @UserId, @TariffName)
	end try
BEGIN catch
	declare @date datetime = GETDATE()
	Insert into FailureInput values ('PhoneNumbers', 'invalid input', @date)
end catch
Go
