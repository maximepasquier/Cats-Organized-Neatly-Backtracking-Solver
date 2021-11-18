#include "file_functions.hpp"
#include <fstream>

void read_game_config_file(std::string path, int &grid_size, int &number_of_different_cats, int &cats_size, int &number_of_cats, std::vector<std::string> &cats_list)
{
    std::ifstream config_file;
    config_file.open(path);
    std::string line;
    while (getline(config_file, line))
    {
        std::string delimiter = " = ";
        size_t position_of_delimiter = line.find(delimiter);
        //+ key est l'identificateur
        std::string key = line.substr(0, position_of_delimiter);
        //+ value est la valeur associée
        std::string value;
        line.erase(0, position_of_delimiter + delimiter.length());
        value = line;
        //+ Associer les values aux clefs
        if (key == "GridSize")
        {
            grid_size = stoi(value);
        }
        else if (key == "NumberOfDifferentCats")
        {
            number_of_different_cats = stoi(value);
        }
        else if (key == "SizeOfCats")
        {
            cats_size = stoi(value);
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
                cats_list.push_back(value_parsed);
                value.erase(0, position_delimiter + delimiter_list.length());
            }
        }
    }
}

void read_game_grid_file(std::string path, int **game_grid, int grid_size)
{
    std::ifstream grid;
    grid.open(path);
    std::string line;
    for (size_t i = 0; i < grid_size; i++)
    {
        getline(grid, line);
        for (size_t j = 0; j < grid_size; j++)
        {
            char c = line[2*j];
            game_grid[i][j] = std::stoi(&c);
        }
    }
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
                cat_array[iterator]->set_matrix(line);
                iterator++;
                break;
            }
        }
        cats_shapes.clear();
        cats_shapes.seekg(0);
    }
    cats_shapes.close();
}