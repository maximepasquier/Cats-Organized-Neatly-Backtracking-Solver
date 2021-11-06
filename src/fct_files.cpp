#include <iostream>
#include <fstream>

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
        //std::cout << line << std::endl;

        std::string delimiter = " = ";
        std::string key = line.substr(0, line.find(delimiter));
        std::string value;
        //std::cout << "key : " << key << std::endl;

        line.erase(0, line.find(delimiter) + delimiter.length());
        value = line;

        //std::cout << "value : " << value << std::endl;

        //getline(is_line, value);
        if (key == "NumberOfDifferentCats")
        {
            number_of_different_cats = stoi(value);
            //std::cout << "number_of_different_cats : " << number_of_different_cats << std::endl;
        }
        else if (key == "MaximumSizeOfCats")
        {
            maximum_cat_shape = stoi(value);
        }
    }
    config_cats.close();
}
void get_cats_shapes(std::string path) {}