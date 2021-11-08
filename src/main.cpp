#include <iostream>
#include <vector>
#include "fct_files.hpp"
#include "Cat.hpp"

int main()
{
    int number_of_different_cats, maximum_cat_shape, number_of_cats;
    std::vector<std::string> list_of_cats;

    get_cats_config("./CatsConfig.txt", number_of_different_cats, maximum_cat_shape, number_of_cats, list_of_cats);
    std::cout << "Number of different cats is : " << number_of_different_cats << std::endl;
    std::cout << "Number of cats is : " << number_of_cats << std::endl;
    std::cout << "Maximum shape of cats is : " << maximum_cat_shape << std::endl;

    std::cout << "list of cats : ";
    for (std::string s : list_of_cats)
    {
        std::cout << s << " ";
    }
    std::cout << std::endl;

    Cat *cat_array[number_of_cats];

    for (size_t i = 0; i < number_of_cats; i++)
    {
        cat_array[i] = new Cat(maximum_cat_shape);
    }

    get_cats_shapes("./CatsShapes.txt", cat_array, list_of_cats);

    cat_array[0]->print_matrix();
    cat_array[1]->print_matrix();
    cat_array[2]->print_matrix();
    cat_array[3]->print_matrix();
    cat_array[4]->print_matrix();
    cat_array[5]->print_matrix();
    cat_array[6]->print_matrix();
    cat_array[7]->print_matrix();

    return 0;
}