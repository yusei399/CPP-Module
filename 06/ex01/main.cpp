#include <cstdint>
#include <iomanip>
#include <iostream>

typedef struct 
{
	int 	id;
	const char    *msg;
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
    Data      data;
    data.id = 42;
    data.msg = "Hello World!";

    Data *ptr = &data;
    uintptr_t raw = serialize(ptr);
    Data*     ptr2 = deserialize(raw);

    std::cout << "Original pointer: " << ptr << std::endl;
    std::cout << "Deserialized pointer: " << ptr2 << std::endl;
    std::cout << "Pointers are equal: " << (ptr == ptr2) << std::endl;
}