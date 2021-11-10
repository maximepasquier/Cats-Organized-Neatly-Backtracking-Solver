#include "Cat.hpp"

Cat::Cat(int size)
{
    this->size = size;
    shape = new int *[size];
    for (size_t i = 0; i < size; i++)
    {
        shape[i] = new int[size];
    }
    iterator_grid_position_line = 0;
    iterator_grid_position_column = 0;
    iterator_rotation = 0;
    already_placed = false;
}

Cat::~Cat()
{
}

void Cat::Set_cat_number(int number)
{
    cat_number = number;
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
    //+ Check if object already placed in game_grid
    if (already_placed)
    {
        for (int grid_line = iterator_grid_position_line; grid_line < iterator_grid_position_line + size; grid_line++)
        {
            for (int grid_column = iterator_grid_position_column; grid_column < iterator_grid_position_column + size; grid_column++)
            {
                if (shape[grid_line - iterator_grid_position_line][grid_column - iterator_grid_position_column] == 1)
                {
                    game_grid[grid_line][grid_column] = 0;
                }
            }
        }
        already_placed = false;
        increment_position_iterators(grid_size);
    }
    //+ Place the cat on the next position
    for (int grid_line = iterator_grid_position_line; grid_line < iterator_grid_position_line + size; grid_line++)
    {
        for (int grid_column = iterator_grid_position_column; grid_column < iterator_grid_position_column + size; grid_column++)
        {
            //+ Vérifie si le placement est correcte
            if (game_grid[grid_line][grid_column] & shape[grid_line - iterator_grid_position_line][grid_column - iterator_grid_position_column])
            {
                if (rotate_shape())
                {
                    if (iterator_grid_position_line == grid_size - size && iterator_grid_position_column == grid_size - size)
                    {
                        //+ Rester iterators
                        iterator_grid_position_line = 0;
                        iterator_grid_position_column = 0;
                        iterator_rotation = 0;
                        already_placed = false;
                        //std::cout << "FALSE!" << std::endl;
                        return false;
                    }
                    increment_position_iterators(grid_size);
                }
                return place_cat(game_grid, grid_size);
            }
        }
    }
    //+ Modify game_grid
    already_placed = true;
    for (int grid_line = iterator_grid_position_line; grid_line < iterator_grid_position_line + size; grid_line++)
    {
        for (int grid_column = iterator_grid_position_column; grid_column < iterator_grid_position_column + size; grid_column++)
        {
            if (shape[grid_line - iterator_grid_position_line][grid_column - iterator_grid_position_column] | game_grid[grid_line][grid_column])
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
        iterator_rotation = 0;
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
    if (iterator_grid_position_column == grid_size - size)
    {
        iterator_grid_position_line++;
        iterator_grid_position_column = 0;
    }
    else
    {
        iterator_grid_position_column++;
    }
}