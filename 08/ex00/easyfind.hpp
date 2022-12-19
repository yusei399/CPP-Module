#ifndef EASYFIND_HPP
#define EASYFIND_HPP

template <typename T>
bool easyfind(T container, int n)
{
    return std::find(container.begin(), container.end(), n) != container.end();
}

template <typename T>
void test(T container, int n)
{
    if (easyfind(container, n))
        std::cout << n << " found\n";
    else
        std::cout << n << " not found\n";
}


#endif