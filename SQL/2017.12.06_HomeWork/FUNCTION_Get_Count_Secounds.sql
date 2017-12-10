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
