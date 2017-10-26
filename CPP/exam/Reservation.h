#pragma once
#include <memory>
#include <functional>
#include "Date.h"
#include "Account.h"
#include "HotelRoom.h"
#include "Date.h"

class Reservation
{
private:
	struct Date m_dateArrival;
	struct Date m_dateCheckOut;
	int m_countPersons;
	std::shared_ptr<HotelRoom> m_hotelRoom;
	std::string m_userName;
	
public:
	Reservation(Date dateArrival, Date dateCheckOut, int countPersons,
		std::shared_ptr<HotelRoom> hotelRoom, std::string account);
	~Reservation();
	std::string GetDateArrivalStr();
	std::string GetDateCheckOutStr();
	Date GetDateArrival() const;
	Date GetDateCheckOut() const;
	int GetCountPerson() const;
	std::shared_ptr<HotelRoom> GetHotelRoom() const;
	std::string GetUserName() const;
	int GetIdRoom() const;
	int GetCapacityRoom();
	double GetCostRoom();
	bool DateIsAvailible(Date startDate, Date finishDate);
};

