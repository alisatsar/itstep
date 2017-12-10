CREATE PROCEDURE InsertPhoneCalls (
@DateCallsB datetime,
@DateCallsE datetime,
@PhoneNumber int,
@Prefix int)
As 
begin Try
	insert into PhoneCalls values (@DateCallsB, @DateCallsE, @PhoneNumber, @Prefix)
	end try
BEGIN catch
	declare @date datetime = GETDATE()
	Insert into FailureInput values ('PhoneCalls', 'invalid input', @date)
end catch
Go
