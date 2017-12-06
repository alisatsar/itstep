SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
-- =============================================
-- Author:		<Author,,Name>
-- Create date: <Create Date,,>
-- Description:	<Description,,>
-- =============================================
CREATE FUNCTION Get_Count_Secounds(@PhoneNumber int)
RETURNS int  
BEGIN
	Declare @result int,@seconds int, @dateBegin datetime, @dateEnd datetime
	Select @dateBegin = PhoneCalls.DateCallsBegin,
	 @dateEnd = DateCallsEnd,
	@seconds = Datediff (second, @dateBegin, @dateEnd)
	FROM PhoneCalls
	WHERE @PhoneNumber = PhoneNumber
	RETURN @seconds
END
GO

http://www.sql.ru/faq/faq_topic.aspx?fid=129

select dbo.Get_Count_Secounds('9396463')
