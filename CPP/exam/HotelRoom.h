#pragma once

class HotelRoom
{
private:
	int m_idRoom;
	int m_capacityRoom;
	double m_cost;	

public:
	HotelRoom(int idRoom, int capacity, double cost);
	~HotelRoom() = default;
	int GetCapacityRoom() const;
	double GetCostRoom() const;
	void SetCostRoom(double cost);
	int GetIdRoom() const;	
};
