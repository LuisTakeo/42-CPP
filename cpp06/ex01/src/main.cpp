#include "main.hpp"

int main(void)
{
	Data		data;
	Data		*ptr;
	uintptr_t	raw;

	//Test 1
	std::cout << "Test 1: Convert a data structure to a raw data" << std::endl;
	data.name = "AnteDEGEMON";
	data.age = 42;
	std::cout << "Data: " << data.name << " " << data.age << std::endl;
	raw = Serializer::serialize(&data);
	std::cout << "Result of the serialize, raw: " << raw << std::endl;

	//Test 2
	std::cout << "Test 2: Convert a raw data to a data structure" << std::endl;
	ptr = Serializer::deserialize(raw);
	std::cout << "Result of deserialize: Name - " << ptr->name << ". Age - " << ptr->age << std::endl;

	//Test 3
	std::cout << "Test 3: Convert a null pointer to a raw data" << std::endl;
	Data		*nullToPtr = NULL;
	raw = Serializer::serialize(nullToPtr);
	std::cout << "Result of the serialize, raw: " << raw << std::endl;

	//Test 4
	std::cout << "Test 4: Convert an invalid pointer" << std::endl;
	Data		*invalidPtr = reinterpret_cast<Data *>(0xdeadc0de);
	raw = Serializer::serialize(invalidPtr);
	std::cout << "Result of the serialize, raw: " << raw << std::endl;
	ptr = Serializer::deserialize(raw);
	std::cout << "Result of the deserialize, Data: " << ptr << std::endl;
	// the following line will cause a segmentation fault
	// std::cout << "Result: Name - " << ptr->name << ". Age - " << ptr->age << std::endl;
	std::cout << "End!" << std::endl << "Segfault! Ops, kiddin xd" << std::endl;
	return 0;
}