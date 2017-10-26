#include "HotelRoom.h"

HotelRoom::HotelRoom(int idRoom, int capacity, double cost) :
	m_idRoom(idRoom), m_capacityRoom(capacity), m_cost(cost)
{	
}

int HotelRoom::GetCapacityRoom() const
{
	return m_capacityRoom;
}

double HotelRoom::GetCostRoom() const
{
	return m_cost;
}

void HotelRoom::SetCostRoom(double cost)
{
	m_cost = cost;
}

int HotelRoom::GetIdRoom() const
{
	return m_idRoom;
}