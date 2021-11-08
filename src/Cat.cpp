#include "Cat.hpp"
#include <iostream>

Cat::Cat(int size)
{
    this->size = size;
    shape = new int *[size];
    for (size_t i = 0; i < size; i++)
    {
        shape[i] = new int[size];
    }
}

Cat::~Cat()
{
}

void Cat::Set_matrix(std::string values)
{
    std::cout << values << std::endl;
    int iterator = 0;
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            char c = values[iterator];
            shape[i][j] = std::stoi(&c);
            iterator+=2;
        }
    }
}

void Cat::print_matrix()
{
    std::cout << "Matrix of this cat is : " << std::endl;
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            std::cout << shape[i][j] << " ";
        }
        std::cout << std::endl;
    }
}