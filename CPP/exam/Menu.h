#pragma once
#include <memory>
#include "Hotel.h"

enum MenuItem
{
	LogIn = 1,
	SignUp = 2,
	LogUot = 3,
	ExitTheProgram = 4,
	AddHotelRoom = 5,
	ViewReservation = 6,
	ViewFreeHotelRoom = 7,
	FindMyBookedRooms = 8,
	ShowAvailiableRooms = 9,
	CancelReservation = 10
};

class Menu
{
private:
	std::unique_ptr<Hotel> m_hotel;
public:
	Menu();
	~Menu();
	void StartMenu();
	void PrintStars();
	void Action(int choice);
	void AnotherAction();
	void LogInSystem();
	void SelectActionManager();
	void SelectActionUser();
};

