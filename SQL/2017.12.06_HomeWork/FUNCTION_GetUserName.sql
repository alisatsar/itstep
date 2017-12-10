USE [PhoneNumbers]
GO
/****** Object:  UserDefinedFunction [dbo].[GetUserName]    Script Date: 10.12.2017 20:42:35 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
Create FUNCTION [dbo].[GetUserName] 
(	
	@PhoneNumber int
)
RETURNS TABLE 
AS
RETURN 
(
	Select FirstName, SecondName 
	FROM UserData, PhoneNumber
	where PhoneNumber.UserId = UserData.UserId
	and PhoneNumber.PhoneNumber = @PhoneNumber
)
