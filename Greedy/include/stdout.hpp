#include <iostream>
#include <vector>
#include "Cat.hpp"

void print_config_infos(int grid_size, int number_of_different_cats, int cats_size, int number_of_cats, std::vector<std::string> cats_list);
template <typename M, typename S>
void print_matrix(M matrix, S size);
void print_all_cats(Cat *cat_array[], int number_of_cats);

template <typename M, typename S>
void print_matrix(M matrix, S size)
{
    std::cout << std::endl;
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}