#include "Menu.h"

Menu::Menu()
{
	m_hotel = std::unique_ptr<Hotel>(new Hotel);
	
	m_hotel->ReadToFileAccount();
	if (m_hotel->FileIsEmpty("fileHotelRoom.txt"))
	{
		m_hotel->CreateHotelRooms();
	}
	else
	{
		m_hotel->ReadToFileHotelRoom();
	}
	m_hotel->ReadToFileReservation();
}

Menu::~Menu()
{
}

//функция первоначального меню при входе в программу
void Menu::StartMenu()
{
	std::cout << "Please log in for further work! Or sign up!" << std::endl;
	int choice;
	do
	{
		PrintStars();
		std::cout << "Log in = 1\nSign up = 2\nExit the program = 4" << std::endl;
		PrintStars();

		std::cin >> choice;

	} while (choice != 1 && choice != 2 && choice != 4);

	Action(choice);
}

//печатаем разделительные звездочки для меню
void Menu::PrintStars()
{
	std::cout << "***********************************" << std::endl;
}

//функция выбора из меню
void Menu::Action(int choice)
{
	switch (choice)
	{
	case LogIn:		
		LogInSystem();
		AnotherAction();
		return;
	case SignUp:
		m_hotel->CreateNewAccount();
		AnotherAction();
		return;
	case LogUot:
		m_hotel->LogOut();
		AnotherAction();
		return;
	case ExitTheProgram:
		m_hotel->AddToFileReservation();
		exit(1);
	case AddHotelRoom:
		m_hotel->AddHotelRoom();
		AnotherAction();
		return;
	case ViewReservation:
		m_hotel->ShowAllReservations();
		AnotherAction();
		return;
	case ViewFreeHotelRoom:
		m_hotel->ViewFreeHotelRoom();
		AnotherAction();
		return;
	case FindMyBookedRooms:
		m_hotel->ShowUserReservation();
		m_hotel->PrintReservation();
		AnotherAction();
		return;
	case ShowAvailiableRooms:
		m_hotel->FindAppropriateRoom();		
		AnotherAction();
		return;	
	case CancelReservation:
		m_hotel->PrintReservation();
		m_hotel->CancelReservation();
		AnotherAction();
		return;
	}
}

void Menu::AnotherAction()
{
	std::string type;
	if (m_hotel.get()->GetCurrentAccountPtr() == nullptr)
	{
		StartMenu();
		return;
	}
	else
	{
		type = (std::string)m_hotel.get()->GetCurrentAccountType();
	}	 

	
	if (type == "Manager")
	{
		SelectActionManager();
	}
	else
	{
		SelectActionUser();
	}
}

//функция входа в программу
void Menu::LogInSystem()
{
	std::string login;
	std::string password;
	std::cout << "Enter login: ";
	std::cin >> login;	

	int position = m_hotel.get()->FindAccount(login);	
	
	if (position < 0)
	{
		std::cout << "This account is not exist." << std::endl;		
	}
	else if (position >= 0)
	{
		std::cout << "Enter password: ";
		std::cin >> password;
		
		if (m_hotel.get()->CheckPassword(password, position))
		{
			m_hotel.get()->SetCurrentAccount(position);
		}
		else
		{
			std::cout << "Invalid password." << std::endl;
		}
	}	
}

//функция меню для менеджера
void Menu::SelectActionManager()
{
	std::cout << "Please, select a next action: " << std::endl;
	int choice = 0;
	do
	{
		PrintStars();
		std::cout << "Log uot - 3\nExit the program - 4\nAdd hotel room - 5\nView booked rooms - 6\nView free rooms - 7" << std::endl;
		PrintStars();

		std::cin >> choice;

	} while (choice <= 2 && choice >= 8);

	Action(choice);
}

//функция меню для пользователя
void Menu::SelectActionUser()
{
	std::cout << "please select a next action: " << std::endl;

	int choice = 0;
	do
	{
		PrintStars();
		std::cout << "Log uot - 3\nExit the program - 4\nFind my booked rooms - 8\nShow availiable rooms - 9\n" <<
			"To cancel of reservation - 10" << std::endl;
		
		PrintStars();

		std::cin >> choice;

	} while (choice != 3 && choice != 4 && choice != 8 && choice != 9 && choice != 10);

	Action(choice);
}