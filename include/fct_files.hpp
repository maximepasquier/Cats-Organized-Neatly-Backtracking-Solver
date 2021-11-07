#include <string>
#include "Cat.hpp"

void get_cats_config(std::string path, int &number_of_different_cats, int &maximum_cat_shape, int &number_of_cats, std::vector<std::string> &list_of_cats);
void get_cats_shapes(std::string path, Cat cat_array[],  std::vector<std::string> list_of_cats);