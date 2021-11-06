#include <iostream>
#include <fstream>
#include <vector>

//#include <math.h>
//#include <algorithm>
#include <sstream>
//#include <sys/stat.h>

#include "fct_files.hpp"

void get_cats_config(std::string path, int &number_of_different_cats, int &maximum_cat_shape)
{
    std::ifstream config_cats;
    config_cats.open(path);
    std::string line;
    int count = 0;
    while (getline(config_cats, line))
    {
        std::istringstream is_line(line);
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
    }
    config_cats.close();
}
void get_cats_shapes(std::string path) {}