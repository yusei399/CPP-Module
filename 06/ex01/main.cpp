#include <cstdint>
#include <iomanip>
#include <iostream>

typedef struct 
{
	const char *msg;
	int 	error;
} Data;

uintptr_t serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}

int main()
{
    Data      data = { "Message", 0 };
    uintptr_t raw = serialize(&data);
    Data*     ptr = deserialize(raw);

    std::cout << "Raw: 0x" << std::hex << raw << "\n"
				<< "Ptr: " << ptr << "\n";
    std::cout << "Data->msg: " << ptr->msg << "\nData->error: " << ptr->error << "\n";
}