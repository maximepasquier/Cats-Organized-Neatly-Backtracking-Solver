#include "stdout.hpp"

void print_config_infos(int grid_size, int number_of_different_cats, int cats_size, int number_of_cats, std::vector<std::string> cats_list)
{
    std::cout << "Game parameters -----------------------------------------------------------------" << std::endl;
    std::cout << "Grid size is : " << grid_size << std::endl;
    std::cout << "Number of different cats is : " << number_of_different_cats << std::endl;
    std::cout << "Size of cats is : " << cats_size << std::endl;
    std::cout << "Number of cats is : " << number_of_cats << std::endl;
    std::cout << "List of cats is : ";
    for (std::string cat : cats_list)
    {
        std::cout << cat << " ";
    }
    std::cout << std::endl;
    std::cout << "---------------------------------------------------------------------------------"<< std::endl;
}


void print_all_cats(Cat *cat_array[], int number_of_cats)
{
    std::cout << "The matrices of all the cats are ------------------------------------------------" << std::endl;
    for (size_t i = 0; i < number_of_cats; i++)
    {
        cat_array[i]->print_matrix();
    }
    std::cout << "---------------------------------------------------------------------------------" << std::endl;
}