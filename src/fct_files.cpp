#include <iostream>
#include <fstream>
#include <vector>
#include <limits.h>

#include <sstream>

#include "fct_files.hpp"

void get_cats_config(std::string path, int &number_of_different_cats, int &maximum_cat_shape, int &number_of_cats, std::vector<std::string> &list_of_cats)
{
    std::ifstream config_cats;
    config_cats.open(path);
    std::string line;
    int count = 0;
    while (getline(config_cats, line))
    {
        //std::istringstream is_line(line);
        std::string delimiter = " = ";
        size_t position_delimiter = line.find(delimiter);
        std::string key = line.substr(0, position_delimiter);
        std::string value;

        line.erase(0, position_delimiter + delimiter.length());
        value = line;

        if (key == "NumberOfDifferentCats")
        {
            number_of_different_cats = stoi(value);
        }
        else if (key == "MaximumSizeOfCats")
        {
            maximum_cat_shape = stoi(value);
        }
        else if (key == "NumberOfCats")
        {
            number_of_cats = stoi(value);
        }
        else if (key == "ListOfCats")
        {
            std::string delimiter_list = ",";
            bool continue_reading = true;
            while (continue_reading)
            {
                size_t position_delimiter = value.find(delimiter_list);
                if (position_delimiter == ULLONG_MAX)
                {
                    continue_reading = false;
                }
                std::string value_parsed = value.substr(0, position_delimiter);
                list_of_cats.push_back(value_parsed);
                value.erase(0, position_delimiter + delimiter_list.length());
            }
        }
    }
    config_cats.close();
}
void get_cats_shapes(std::string path, Cat *cat_array[], std::vector<std::string> list_of_cats)
{
    std::ifstream cats_shapes;
    cats_shapes.open(path);

    int iterator = 0;
    for (std::string cat_key : list_of_cats)
    {
        std::string line;
        while (getline(cats_shapes, line))
        {
            std::string delimiter = " = ";
            size_t position_delimiter = line.find(delimiter);
            std::string key = line.substr(0, position_delimiter);
            if (key == cat_key)
            {
                line.erase(0, position_delimiter + delimiter.length());
                cat_array[iterator]->Set_matrix(line);
                iterator++;
                break;
            }
        }
        cats_shapes.clear();
        cats_shapes.seekg(0);
    }
    cats_shapes.close();
}

void get_grid_size(std::string path, int &grid_size)
{
    std::ifstream grid_config;
    grid_config.open(path);
    std::string line;
    int count = 0;
    while (getline(grid_config, line))
    {
        std::string delimiter = " = ";
        size_t position_delimiter = line.find(delimiter);
        std::string key = line.substr(0, position_delimiter);
        std::string value;

        line.erase(0, position_delimiter + delimiter.length());
        value = line;

        if (key == "GridSize")
        {
            grid_size = stoi(value);
        }
    }
    grid_config.close();
}

void get_grid(std::string path, int **game_grid, int grid_size)
{
    std::ifstream grid;
    grid.open(path);
    std::string line;
    int column = 0;
    while (getline(grid, line))
    {
        for (size_t i = 0; i < grid_size; i++)
        {
            char c = line[2*i];
            game_grid[i][column] = std::stoi(&c);
        }
        column++;
    }
}

void print_grid(int **game_grid, int grid_size)
{
    for (size_t i = 0; i < grid_size; i++)
    {
        for (size_t j = 0; j < grid_size; j++)
        {
            std::cout << game_grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}