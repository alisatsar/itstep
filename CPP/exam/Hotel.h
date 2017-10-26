#pragma once
#include <vector>
#include <list>
#include <memory>
#include <string>
#include <fstream>
#include "HotelRoom.h"
#include "Manager.h"
#include "User.h"
#include "Reservation.h"

class Hotel
{
private:
	std::vector<std::shared_ptr<Account>> m_accounts;
	std::list<std::shared_ptr<HotelRoom>> m_hotelRooms;
	std::shared_ptr<Account> m_currentAccount;
	std::vector<std::shared_ptr<Reservation>> m_reservations;
	std::vector<std::shared_ptr<HotelRoom>> m_availible;
	std::vector<std::shared_ptr<Reservation>> m_myReservations;
public:
	Hotel();
	std::shared_ptr<Account> GetCurrentAccountPtr();
	std::string GetCurrentAccountType() const;
	void SetCurrentAccount(int position);
	void CreateHotelRooms();
	void CreateNewAccount();
	int FindAccount(const std::string& login);
	bool CheckPassword(const std::string& password, int position);
	void LogOut();
	void AddHotelRoom();
	void AddToFileAccount(const Account& account);
	void ReadToFileAccount();
	void AddToFileHotelRoom(const HotelRoom& hotelRoom);
	bool FileIsEmpty(const std::string& fileName);
	void ReadToFileHotelRoom();
	void FindAppropriateRoom();
	Date AskDate();
	int GetDays(std::uint16_t month, std::uint16_t year);
	void PrintAvailibleHotelRooms();
	bool IsEmptyAvailibleRooms();
	void ReserveRoom(Date dateArrival, Date dateCheckOut, int count);
	std::shared_ptr<HotelRoom> FindHotelRoom(int id);
	void ShowUserReservation();
	void PrintReservation();
	void CancelReservation();
	void Hotel::DeleteReservation(Date date, int id);
	bool IsReservationCanBeCancelled(Date const& dateRes, Date const& dateCancel);
	void ShowAllReservations();
	void ViewFreeHotelRoom();
	bool FindReservation(int id, Date date);
	void AddToFileReservation();
	void ReadToFileReservation();
};