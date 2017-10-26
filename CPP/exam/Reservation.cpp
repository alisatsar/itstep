#include "Reservation.h"

Reservation::Reservation(Date dateArrival, Date dateCheckOut, int countPersons,
	std::shared_ptr<HotelRoom> hotelRoom, std::string account) :
	m_dateArrival(Date(dateArrival)), m_dateCheckOut(Date(dateCheckOut)), m_countPersons(countPersons),
	m_hotelRoom(hotelRoom), m_userName(account)
{	
	
}

Reservation::~Reservation()
{
}

std::string Reservation::GetDateArrivalStr()
{
	return m_dateArrival.ToString();
}

std::string Reservation::GetDateCheckOutStr()
{
	return m_dateCheckOut.ToString();
}

Date Reservation::GetDateArrival() const
{
	return m_dateArrival;
}

Date Reservation::GetDateCheckOut() const
{
	return m_dateCheckOut;
}

int Reservation::GetCountPerson() const
{
	return m_countPersons;
}

std::shared_ptr<HotelRoom> Reservation::GetHotelRoom() const
{
	return m_hotelRoom;
}

std::string Reservation::GetUserName() const
{
	return m_userName;
}

int Reservation::GetIdRoom() const
{
	return m_hotelRoom.get()->GetIdRoom();
}

int Reservation::GetCapacityRoom()
{
	return m_hotelRoom.get()->GetCapacityRoom();
}

double Reservation::GetCostRoom()
{
	return m_hotelRoom.get()->GetCostRoom();
}

bool Reservation::DateIsAvailible(Date startDate, Date finishDate)
{
	if (m_dateCheckOut < startDate || finishDate < m_dateArrival)
	{		
		return true;			
	}
	return false;
}
