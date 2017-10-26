#include "Hotel.h"

Hotel::Hotel()
{	
	//m_accounts.push_back(std::make_shared<Manager>("Manager", "123", true));
	m_currentAccount = nullptr;
}

std::shared_ptr<Account> Hotel::GetCurrentAccountPtr()
{
	return m_currentAccount;
}

std::string Hotel::GetCurrentAccountType() const
{
	return m_currentAccount.get()->GetAccountType();
}

void Hotel::SetCurrentAccount(int position)
{
	m_currentAccount.reset();	
	m_currentAccount = m_accounts[position];
}

//создаем по пять номеров разной capacity и добавляем их в список доступных номеров
void Hotel::CreateHotelRooms()
{
	int capacity = 1;
	double cost = 10;
	int id = 100;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			id++;
			m_hotelRooms.push_back(std::make_shared<HotelRoom>(capacity, cost, id));			
		}
		cost = cost * 2 / 1.4;
		id = id + 100 - 5;
		capacity++;
	}
	if (FileIsEmpty("fileHotelRoom.txt"))
	{
		for (auto it = m_hotelRooms.begin(); it != m_hotelRooms.end(); it++)
		{			
			AddToFileHotelRoom(*(it->get()));
		}
	}
}

void Hotel::CreateNewAccount()
{
	std::string login;
	std::string password;
	std::string passwordCheck;

	do
	{
		std::cout << "Enter a new login: ";
		std::cin >> login;
	} while (FindAccount(login) != -1);

	std::cout << "Enter password: ";
	std::cin >> password;

	do
	{
		std::cout << "Repeat password: ";
		std::cin >> passwordCheck;
	} while (passwordCheck != password);

	std::cout << "The password is correct!" << std::endl;

	m_currentAccount = std::make_shared<User>(login, password);
	m_accounts.push_back(m_currentAccount);
	AddToFileAccount(*(m_currentAccount.get()));
}

//возвращаем позицию, для того, чтобы не искать ее по массиву
//постоянно и присваивать m_currentAccount по индексу из 
//vector m_accounts
//eсли не нашли, возвращаем -1
int Hotel::FindAccount(const std::string& login)
{
	if (!m_accounts.empty())
	{
		for (size_t i = 0; i < m_accounts.size(); i++)
		{
			if (m_accounts[i].get()->GetLogin() == login)
			{
				return i;
			}			
		}
	}
	return -1;
}

bool Hotel::CheckPassword(const std::string& password, int position)
{
	if (position >= 0)
	{
		return m_accounts[position].get()->GetPassword() == password;
	}
	return false;
}

void Hotel::LogOut()
{		
	m_currentAccount = nullptr;
}

void Hotel::AddHotelRoom()
{
	int capacity;

	do
	{
		std::cout << "Enter a capacity of the room (1 - 4): ";
		std::cin >> capacity;
	} while (capacity <= 0 || capacity >= 5);

	double cost;
	std::cout << "Enter a cost of the room: ";
	std::cin >> cost;

	//генерируем новый id
	int newId = 0;
	for (auto it = m_hotelRooms.begin(); it != m_hotelRooms.end(); it++)
	{
		if (it->get()->GetCapacityRoom() == capacity)
		{
			newId = it->get()->GetIdRoom() + 1;
		}
	}

	auto newRoom = std::make_shared<HotelRoom>(capacity, cost, newId);
	m_hotelRooms.push_back(newRoom);
	AddToFileHotelRoom(*(newRoom.get()));	
}

void Hotel::AddToFileAccount(const Account& account)
{
	std::ofstream ofile("fileAccount.txt", std::ios::out | std::ios::app);

	if (!ofile.is_open())
	{
		std::cout << "File is not open" << std::endl;
	}

	std::string strForWrite = account.GetAccountType() + " " +
		account.GetLogin() + " " + account.GetPassword() + "\n";

	ofile.write(strForWrite.c_str(), strForWrite.size());
	ofile.close();
}

void Hotel::ReadToFileAccount()
{
	std::ifstream ifile("fileAccount.txt");

	if (!ifile.is_open())
	{
		std::cout << "File is not open." << std::endl;
	}

	std::string type;
	std::string login;
	std::string password;
	std::shared_ptr<Account> m = nullptr;

	while (!ifile.eof())
	{
		m.reset();
		ifile >> type;
		ifile >> login;
		ifile >> password;
		if (type == "Manager")
		{
			m = std::make_shared<Manager>(login, password, true);
		}
		else if (type == "User")
		{
			m = std::make_shared<User>(login, password);
		}
		m_accounts.push_back(m);
	}
	m_accounts.pop_back();
	ifile.close();
}

void Hotel::AddToFileHotelRoom(const HotelRoom& hotelRoom)
{
	std::ofstream ofile("fileHotelRoom.txt", std::ios::out | std::ios::app);

	if (!ofile.is_open())
	{
		std::cout << "File is not open" << std::endl;
	}

	std::string capacityStr = std::to_string(hotelRoom.GetCapacityRoom());
	std::string costStr = std::to_string(hotelRoom.GetCostRoom());
	std::string idStr = std::to_string(hotelRoom.GetIdRoom());
	std::string strForWrite = idStr + " " +
		capacityStr + " " + costStr + "\n";

	ofile.write(strForWrite.c_str(), strForWrite.size());
	ofile.close();
}

bool Hotel::FileIsEmpty(const std::string& fileName)
{
	std::ifstream ifile(fileName);
	long size;
	ifile.seekg(0, std::ios::end);
	size = ifile.tellg();
	ifile.close();
	if (size == 0)
	{
		return true;
	}
	return false;
}

void Hotel::ReadToFileHotelRoom()
{
	std::ifstream ifile("fileHotelRoom.txt");

	if (!ifile.is_open())
	{
		std::cout << "File is not open." << std::endl;
	}

	std::string idStr;
	std::string capacityStr;
	std::string costStr;
	int id;
	int capacityRoom;
	double cost;	

	std::shared_ptr<HotelRoom> h = nullptr;

	while (!ifile.eof())
	{
		h.reset();
		ifile >> idStr;
		ifile >> capacityStr;
		ifile >> costStr;
		id = atoi(idStr.c_str());
		capacityRoom = atoi(capacityStr.c_str());
		cost = atof(costStr.c_str());
		h = std::make_shared<HotelRoom>(id, capacityRoom, cost);
		m_hotelRooms.push_back(h);
	}
	m_hotelRooms.pop_back();
	ifile.close();
}

void Hotel::FindAppropriateRoom()
{
	m_availible.clear();
	std::cout << "Enter date arrival: " << std::endl;
	Date dateArrival = AskDate();

	Date dateCheckOut;

	do
	{
		std::cout << "Enter date check out :" << std::endl;
		dateCheckOut = AskDate();
	} while (dateCheckOut < dateArrival);

	int persons;
	do
	{
		std::cout << "Enter the count of persons (1 - 4): ";
		std::cin >> persons;
	} while (persons <= 0 || persons >= 5);	

	bool flagPush = false;
		
	for (auto it = m_hotelRooms.begin(); it != m_hotelRooms.end(); ++it)
	{
		if (persons == it->get()->GetCapacityRoom())
		{
			flagPush = true;
			if (!m_reservations.empty())
			{
				for (auto res = m_reservations.begin(); res != m_reservations.end(); ++res)
				{
					if ((res->get()->GetIdRoom() == it->get()->GetIdRoom()) && !(res->get()->DateIsAvailible(dateArrival, dateCheckOut)))
					{	
						flagPush = false;
						break;
					}					
				}				
			}			
		}
		if (flagPush)
		{
			m_availible.push_back(*(it));
		}
		flagPush = false;
	}

	PrintAvailibleHotelRooms();

	int numberType = 1;
	std::cout << "Enter 1 if you want reserve hotel room, or 0 for quit: " << std::endl;
	std::cin >> numberType;

	if (numberType == 0)
	{
		return;
	}

	ReserveRoom(dateArrival, dateCheckOut, persons);
}

Date Hotel::AskDate()
{
	std::chrono::system_clock::time_point tp = std::chrono::system_clock::now();
	std::time_t t = std::chrono::system_clock::to_time_t(tp);
	tm* _tm = std::localtime(&t);

	std::uint16_t year = 0;
	do
	{
		std::cout << "Enter year: ";
		std::cin >> year;
	} while (year < _tm->tm_year + 1900);

	std::uint16_t month = 0;

	do
	{
		std::cout << "Enter month: ";
		std::cin >> month;
	} while (month < _tm->tm_mon + 1 || month >= 13);

	std::uint16_t day;
	std::uint16_t startDate = month == _tm->tm_mon + 1 ? _tm->tm_mday + 1 : 1;
	do
	{
		std::cout << "Enter day: ";
		std::cin >> day;
	} while (day < startDate || day >= GetDays(month, year) + 1);

	return Date(day, month, year);
}

int Hotel::GetDays(std::uint16_t month, std::uint16_t year)
{
	static const int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int result = days[month - 1];;

	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
	{
		++result;
	}

	return result;
}

void Hotel::PrintAvailibleHotelRooms()
{
	for (auto it = m_availible.begin(); it != m_availible.end(); ++it)
	{
		std::cout << "#" << (*it)->GetIdRoom() << std::endl;
		std::cout << "Capacity of room: " << (*it)->GetCapacityRoom() << std::endl;
		std::cout << "Price: " << (*it)->GetCostRoom() << std::endl;
	}
}

bool Hotel::IsEmptyAvailibleRooms()
{
	return m_availible.empty();
}

void Hotel::ReserveRoom(Date dateArrival, Date dateCheckOut, int count)
{
	int answer;

	if (!m_availible.empty())
	{
		int min = m_availible.begin()->get()->GetIdRoom();
		int max = m_availible[m_availible.size() - 1].get()->GetIdRoom();
		do
		{
			std::cout << "Enter id room: " << std::endl;
			std::cin >> answer;
		} while (answer < min || answer > max);

		auto room = FindHotelRoom(answer);

		m_reservations.push_back(std::make_shared<Reservation>(dateArrival, dateCheckOut, count, room, m_currentAccount.get()->GetLogin()));
		m_myReservations.push_back(std::make_shared<Reservation>(dateArrival, dateCheckOut, count, room, m_currentAccount.get()->GetLogin()));
		m_availible.clear();
	}	
}

std::shared_ptr<HotelRoom> Hotel::FindHotelRoom(int id)
{
	for (auto it = m_hotelRooms.begin(); it != m_hotelRooms.end(); it++)
	{
		if (it->get()->GetIdRoom() == id)
		{			
			return *(it);
		}
	}
}

void Hotel::ShowUserReservation()
{
	if (!m_myReservations.empty())
	{
		m_myReservations.clear();
	}
	for (auto it = m_reservations.begin(); it != m_reservations.end(); it++)
	{
		if (m_currentAccount.get()->GetLogin() == it->get()->GetUserName())
		{
			m_myReservations.push_back(std::make_shared<Reservation>(*(it->get())));
		}
	}
}

void Hotel::PrintReservation()
{
	if (!m_myReservations.empty())
	{
		int i = 1;
		for (auto it = m_myReservations.begin(); it != m_myReservations.end(); it++)
		{
			std::cout << "Number: " << i++ << std::endl;
			std::cout << "Arrival date: " << it->get()->GetDateArrivalStr() << std::endl;
			std::cout << "Check out date: " << it->get()->GetDateCheckOutStr() << std::endl;
			std::cout << "Count of persons: " << it->get()->GetCapacityRoom() << std::endl;
			std::cout << "Number of the hotel room: " << it->get()->GetIdRoom() << std::endl;
			std::cout << "Cost of the hotel room: " << it->get()->GetCostRoom() << std::endl;
		}
	}
	else
	{
		std::cout << "You don't have reservations" << std::endl;
	}
}

void Hotel::CancelReservation()
{
	std::chrono::system_clock::time_point tp = std::chrono::system_clock::now();
	std::time_t t = std::chrono::system_clock::to_time_t(tp);
	tm* _tm = std::localtime(&t);

	Date now(tp);
	
	if (!m_myReservations.empty())
	{
		int answer;

		do
		{
			std::cout << "Enter of number reservation: ";
			std::cin >> answer;
		} while (answer <= 0 || answer >= m_myReservations.size() + 1);

		if (IsReservationCanBeCancelled(m_myReservations[answer - 1].get()->GetDateArrival(), now))
		{
			DeleteReservation(m_myReservations[answer - 1].get()->GetDateArrival(), m_myReservations[answer - 1].get()->GetIdRoom());
			m_myReservations.erase(m_myReservations.begin() + answer - 1);
		}
		else
		{
			std::cout << "You can't cancel this reservation." << std::endl;
		}
	}	
}

void Hotel::DeleteReservation(Date date, int id)
{
	Date d;
	int idLocal;
	for (auto it = m_reservations.begin(); it != m_reservations.end(); it++)
	{
		d = it->get()->GetDateArrival();
		idLocal = it->get()->GetIdRoom();
		if (it->get()->GetUserName() == m_currentAccount.get()->GetLogin() && d == date && idLocal == id)
		{
			m_reservations.erase(it);
			return;
		}
	}
}

bool Hotel::IsReservationCanBeCancelled(Date const& dateRes, Date const& dateCancel)
{
	long daysRes;
	long daysCancel;
	if (dateCancel.Year == dateRes.Year)
	{
		if (dateCancel.Month == dateRes.Month)
		{
			return dateRes.Day - dateCancel.Day >= 7;
		}
		else if (dateRes.Month - dateCancel.Month == 1)
		{
			daysRes = GetDays(dateRes.Month - 1, dateRes.Year) + dateRes.Day;
			return daysRes - dateCancel.Day >= 7;
		}
		else if (dateRes.Month - dateCancel.Month > 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (dateRes.Year - dateCancel.Year == 1)
	{
		if (dateRes.Month == 1 && dateCancel.Month == 12)
		{
			return (31 - dateCancel.Day + dateRes.Day) >= 7;
		}
	}

	return true;	
}

void Hotel::ShowAllReservations()
{
	if (!m_reservations.empty())
	{
		int i = 1;
		for (auto it = m_reservations.begin(); it != m_reservations.end(); it++)
		{
			std::cout << "Number: " << i++ << std::endl;
			std::cout << "Arrival date: " << it->get()->GetDateArrivalStr() << std::endl;
			std::cout << "Сheck out date: " << it->get()->GetDateCheckOutStr() << std::endl;
			std::cout << "Count of persons: " << it->get()->GetCapacityRoom() << std::endl;
			std::cout << "Number of the hotel room: " << it->get()->GetIdRoom() << std::endl;
			std::cout << "Cost of the hotel room: " << it->get()->GetCostRoom() << std::endl;
			std::cout << "User: " << it->get()->GetUserName() << std::endl;
		}
	}
	else
	{
		std::cout << "Not yet reservations" << std::endl;
	}
}

void Hotel::ViewFreeHotelRoom()
{
	Date date = AskDate();

	for (auto hr = m_hotelRooms.begin(); hr != m_hotelRooms.end(); hr++)
	{		
		if (!FindReservation(hr->get()->GetIdRoom(), date))
		{
			std::cout << "Number: " << hr->get()->GetIdRoom() << std::endl;
			std::cout << "Cost: " << hr->get()->GetCostRoom() << std::endl;
			std::cout << "Capacity: " << hr->get()->GetCapacityRoom() << std::endl;
		}
	}	
}

bool Hotel::FindReservation(int id, Date date)
{
	for (auto it = m_reservations.begin(); it != m_reservations.end(); it++)
	{
		if ((id == it->get()->GetIdRoom()) && (it->get()->GetDateArrival() < date || date < it->get()->GetDateCheckOut()))
		{
			return true;
		}
	}
	return false;
}

void Hotel::AddToFileReservation()
{
	std::ofstream ofile("fileReservation.txt", std::ios::out | std::ios::app);

	if (!ofile.is_open())
	{
		std::cout << "File is not open" << std::endl;
	}	

	std::string dateArrival;
	std::string dateCheckOut;
	std::string countPerson;
	std::string idHotelRoom;
	std::string userName;
	std::string strForWrite;
	for (auto reservation = m_reservations.begin(); reservation != m_reservations.end(); reservation++)
	{		
		dateArrival = reservation->get()->GetDateArrivalStr();;
		dateCheckOut = reservation->get()->GetDateCheckOutStr();
		countPerson = std::to_string(reservation->get()->GetCountPerson());
		idHotelRoom = std::to_string(reservation->get()->GetIdRoom());
		userName = reservation->get()->GetUserName();
		strForWrite = dateArrival + " " + dateCheckOut + " " +
			countPerson + " " + idHotelRoom + " " + userName + "\n";		
	}	

	ofile.write(strForWrite.c_str(), strForWrite.size());
	ofile.close();
}

void Hotel::ReadToFileReservation()
{
	std::ifstream ifile("fileReservation.txt");

	if (!ifile.is_open())
	{
		std::cout << "File is not open." << std::endl;
	}

	std::string dateArrivalStr;
	std::string dateCheckOutStr;
	std::string countPersonStr;
	std::string idHotelRoomStr;
	std::string userName;
		
	int countPerson;
	int idHotelRoom;	

	std::shared_ptr<Reservation> res = nullptr;

	while (!ifile.eof())
	{
		res.reset();
		ifile >> dateArrivalStr;
		ifile >> dateCheckOutStr;
		ifile >> countPersonStr;
		ifile >> idHotelRoomStr;
		ifile >> userName;

		Date dateArrival(dateArrivalStr);
		Date dateCheckOut(dateCheckOutStr);
		countPerson = atoi(countPersonStr.c_str());
		idHotelRoom = atoi(idHotelRoomStr.c_str());
		
		res = std::make_shared<Reservation>(dateArrival, dateCheckOut, countPerson, FindHotelRoom(idHotelRoom), userName);
		m_reservations.push_back(res);
	}
	m_reservations.pop_back();
	ifile.clear();
	ifile.close();
}