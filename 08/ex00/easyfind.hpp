#ifndef EASYFIND_HPP
#define EASYFIND_HPP

template <typename T>
typename T::iterator easyfind(T container, int n)
{
    return std::find(container.begin(), container.end(), n) != container.end();
}

template <typename T>
void test_vetor(T container, int n)
{
    if (easyfind(container, n))
        std::cout << n << " found\n";
    else
        std::cout << n << " not found\n";
}


template <typename T>
void test_list(T container, int n)
{
    if (easyfind(container, n))
        std::cout << n << " found\n";
    else
        std::cout << n << " not found\n";
}

#endif