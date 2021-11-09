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
    iterator_grid_position_x = size - 1;
    iterator_grid_position_y = size - 1;
    iterator_rotation = 0;
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
            shape[i][j] = c - '0';
            //std::cout << "c is : " << c << ", and val is : " << shape[i][j] << std::endl;
            iterator += 2;
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

bool Cat::place_cat(int **game_grid, int grid_size)
{
    //+ Place the cat on the next position
    for (int grid_line = 0; grid_line < grid_size; grid_line++)
    {
        for (int grid_column = 0; grid_column < grid_size; grid_column++)
        {

            //game_grid[grid_line][grid_column] += shape[iterator_grid_position_x][iterator_grid_position_y];
        }
    }

    return true;
}