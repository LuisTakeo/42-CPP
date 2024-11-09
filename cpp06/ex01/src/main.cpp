#include "main.hpp"

int main(void)
{
	Data		data;
	Data		*ptr;
	uintptr_t	raw;

	data.name = "AnteDEGEMON";
	data.age = 42;
	std::cout << "Data: " << data.name << " " << data.age << std::endl;
	raw = Serializer::serialize(&data);
	std::cout << "Raw: " << raw << std::endl;
	ptr = Serializer::deserialize(raw);
	std::cout << "Data: " << ptr->name << " " << ptr->age << std::endl;
	return 0;
}