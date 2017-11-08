#include <iostream>
#include <vector>
#include <ctime>

using BigData = std::vector<std::vector<std::string>>;

struct Package
{
	BigData m_data;
	Package(const BigData& data) : m_data(data) {}
	Package(BigData&& data) : m_data(std::move(data)) {}
	Package() = delete;

	void send() {}
};

int main()
{	
	auto start_time = clock();
	{
		BigData bigData(10000, std::vector<std::string>(1000, "Data"));
		//1.6 Gb

		Package pck(std::move(bigData));
		pck.send();
	}	

	std::cout << (clock() - start_time) / 1000 << std::endl;

	return 0;
}
