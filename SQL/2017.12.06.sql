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
AS
RETURN 
(
	Declare @result int,@seconds int, @dateBegin datetime, @dateEnd datetime

	Select @dateBegin = PhoneCalls.DateCallsBegin,
	 @dateEnd = DateCallsEnd,
	@seconds = Datediff (second, @dateBegin, @dateEnd)
	FROM PhoneCalls
)
GO
