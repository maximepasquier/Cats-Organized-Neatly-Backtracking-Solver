#include <iostream>
#include "fct_files.hpp"
#include "Cat.hpp"

int main()
{
    int number_of_different_cats, maximum_cat_shape;

    std::cout << "Before : " << number_of_different_cats << " : " << maximum_cat_shape << std::endl;
    get_cats_config("./CatsConfig.txt", number_of_different_cats, maximum_cat_shape);
    std::cout << "After : " << number_of_different_cats << " : " << maximum_cat_shape << std::endl;

    //* Read allCats.txt to get cats shapes
    get_cats_shapes("./allCats.txt");

    return 0;
}