#include "Cat.hpp"

Cat::Cat(int size)
{
    this->matrix_size = size;
    shape = new int *[size];
    for (size_t i = 0; i < size; i++)
    {
        shape[i] = new int[size];
    }
    already_placed = false;
}

Cat::~Cat()
{
}

void Cat::compute_cat_weight()
{
    int weight = 0;
    for (size_t i = 0; i < matrix_size; i++)
    {
        for (size_t j = 0; j < matrix_size; j++)
        {
            weight += shape[i][j];
        }
    }
    cat_weight = weight;
}

void Cat::set_matrix(std::string values)
{
    int iterator = 0;
    for (size_t i = 0; i < matrix_size; i++)
    {
        for (size_t j = 0; j < matrix_size; j++)
        {
            char c = values[iterator];
            shape[i][j] = c - '0';
            iterator += 2;
        }
    }
}

void Cat::print_matrix()
{
    std::cout << "Matrix of this cat is of weight : " << cat_weight << ", and the matrix is :" << std::endl;
    for (size_t i = 0; i < matrix_size; i++)
    {
        for (size_t j = 0; j < matrix_size; j++)
        {
            std::cout << shape[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool Cat::get_availability()
{
    return already_placed;
}

void Cat::set_availability(bool status)
{
    already_placed = status;
}

int Cat::get_weight()
{
    return cat_weight;
}

void Cat::rotate_shape()
{
    
}