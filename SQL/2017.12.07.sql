USE [alisa]
GO
/****** Object:  Trigger [dbo].[insert_PhoneCalls]    Script Date: 07.12.2017 11:39:10 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
ALTER TRIGGER [dbo].[insert_PhoneCalls] ON [dbo].[PhoneCalls]
	after insert
AS
BEGIN
declare @rez int;
select  @rez=(select PhoneNumber from inserted)
print @rez
END

______________________________

USE [alisa]
GO
/****** Object:  Trigger [dbo].[instread_deletePhoneCalls]    Script Date: 07.12.2017 11:39:18 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
ALTER Trigger [dbo].[instread_deletePhoneCalls] On [dbo].[PhoneCalls]
instead of INSERT
AS
BEGIN
declare @res Datetime, @number int, @prefix int
select @res = (select DateCallsEnd from PhoneCalls),
@number = (select PhoneNumber from inserted),
@prefix = (select Prefix from inserted)
--insert into PhoneCalls (DateCallsBegin, DateCallsEnd, PhoneNumber, Prefix)
--values (GETDATE(), @res + 1, @number, @prefix)
END
