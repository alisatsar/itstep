---------------------------------
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

create FUNCTION GetData 
(
)
RETURNS datetime
AS
BEGIN	
	DECLARE @begin datetime = '1912-04-05T11:23:45', 
	@end datetime = '2048-12-17T23:57:18',
	@result datetime;
	set @result = cast(cast(@begin as float) + (cast(@end as float) - cast(@begin as float)) * rand() as datetime)
	RETURN @result
END
GO

http://www.sql.ru/forum/1051566/kak-sgenerirovat-sluchaynuu-datu-lezhashhuu-v-opredelennom-intervale-vremeni-na-t-sql

---------------------
USE [alisa]
GO
/****** Object:  StoredProcedure [dbo].[PrintDate]    Script Date: 12.12.2017 11:33:45 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
ALTER PROCEDURE [dbo].[PrintDate]
As	
	declare @begin datetime, @end datetime;
	select @begin = '1912-04-05T11:23:45', @end = '2048-12-17T23:57:18';
	select @begin as [begin], @end as [end], 
	cast(cast(@begin as float) + (cast(@end as float) - cast(@begin as float)) * rand() as datetime) as [random date];
	Print @begin
  
---------------------------- 
  
USE [alisa]
GO
/****** Object:  StoredProcedure [dbo].[InsertPhoneCalls_random]    Script Date: 12.12.2017 11:34:49 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
ALTER PROCEDURE [dbo].[InsertPhoneCalls_random]
As 
While (select count(DateCallsBegin) from PhoneCalls) < 20
Declare @DateCallsB datetime,
@DateCallsE datetime,
@PhoneNumber int,
@Prefix int
SET @DateCallsB = DATEADD(day, (ABS(CHECKSUM(NEWID())) % 1625), '2015-1-1 00:00:00.001')
Set	@DateCallsE = DATEADD(day, (ABS(CHECKSUM(NEWID())) % 1625), '2015-1-1 00:00:00.001')
select @PhoneNumber=PhoneNumber, @Prefix = Prefix 
from PhoneNumber
begin Try	   
	insert into PhoneCalls values (@DateCallsB, @DateCallsE, @PhoneNumber, @Prefix)
	end try
BEGIN catch
	declare @date datetime = GETDATE()
	Insert into FailureInput values ('PhoneCalls', 'invalid input', @date)
end catch
