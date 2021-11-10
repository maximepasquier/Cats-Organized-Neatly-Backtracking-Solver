#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <limits.h>
#include <sstream>

#include "Cat.hpp"

void get_cats_config(std::string path, int &number_of_different_cats, int &maximum_cat_shape, int &number_of_cats, std::vector<std::string> &list_of_cats);
void get_cats_shapes(std::string path, Cat *cat_array[], std::vector<std::string> list_of_cats);
void get_grid_size(std::string path, int &grid_size);
void set_grid_to_1(int **game_grid_padded, int padded_grid_size);
void get_grid(std::string path, int **game_grid, int grid_size, int maximum_cat_shape);
void print_grid(int **game_grid, int grid_size);
void print_solution(int **game_grid, Cat *cat_array[], int initial_grid_size, int number_of_cats);