#ifndef DEF_CAT
#define DEF_CAT

#include <iostream>
#include <vector>

class Cat
{
private:
    int cat_number;
    int size;
    int **shape;
    int iterator_grid_position_line;
    int iterator_grid_position_column;
    int iterator_rotation;
    bool already_placed;
public:
    Cat(int size);
    ~Cat();
    void Set_cat_number(int number);
    void Set_matrix(std::string values);
    void print_matrix();
    bool place_cat(int ** game_grid,int grid_size);
    bool rotate_shape();
    void increment_position_iterators(int grid_size);
};

#endif