#include <string>
#include <limits.h>
#include <vector>
#include "Cat.hpp"

void read_game_config_file(std::string path, int &grid_size, int &number_of_different_cats, int &cats_size, int &number_of_cats, std::vector<std::string> &cats_list);
void read_game_grid_file(std::string path, int **game_grid, int grid_size);
void get_cats_shapes(std::string path, Cat *cat_array[], std::vector<std::string> list_of_cats);