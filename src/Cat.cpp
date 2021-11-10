#include "Cat.hpp"

Cat::Cat(int size)
{
    this->size = size;
    shape = new int *[size];
    for (size_t i = 0; i < size; i++)
    {
        shape[i] = new int[size];
    }
    iterator_grid_position_x = 0;
    iterator_grid_position_y = 0;
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
    for (int grid_line = iterator_grid_position_x; grid_line < iterator_grid_position_x + size; grid_line++)
    {
        for (int grid_column = iterator_grid_position_y; grid_column < iterator_grid_position_y + size; grid_column++)
        {
            //+ Vérifie si le placement est correcte
            if (game_grid[grid_line][grid_column] & shape[grid_line - iterator_grid_position_x][grid_column - iterator_grid_position_y])
            {
                if (rotate_shape())
                {
                    increment_position_iterators(grid_size);
                }
                return place_cat(game_grid, grid_size);
            }
        }
    }
    //+ Modify game_grid
    for (int grid_line = iterator_grid_position_x; grid_line < iterator_grid_position_x + size; grid_line++)
    {
        for (int grid_column = iterator_grid_position_y; grid_column < iterator_grid_position_y + size; grid_column++)
        {
            if (shape[grid_line - iterator_grid_position_x][grid_column - iterator_grid_position_y] | game_grid[grid_line][grid_column])
            {
                game_grid[grid_line][grid_column] = 1;
            }
            else
            {
                game_grid[grid_line][grid_column] = 0;
            }
        }
    }
    return true;
}

bool Cat::rotate_shape()
{
    int length = size * size;
    int tmp_shape[length];
    int iterator = 0;
    //+ Rotate 90 degrees counterclockwise
    for (int j = size - 1; j >= 0; j--)
    {
        for (int i = 0; i < size; i++)
        {
            tmp_shape[iterator] = shape[i][j];
            iterator++;
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            shape[i][j] = tmp_shape[j + i * size];
        }
    }
    if (iterator_rotation == 3)
    {
        //+ toutes les rotations déjà effectuées
        return true;
    }
    else
    {
        iterator_rotation++;
        return false;
    }
}

void Cat::increment_position_iterators(int grid_size)
{
    if (iterator_grid_position_x == grid_size - 1)
    {
        iterator_grid_position_y++;
    }
    else
    {
        iterator_grid_position_x++;
    }
}