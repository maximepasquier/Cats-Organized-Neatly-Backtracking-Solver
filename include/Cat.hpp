#ifndef DEF_CAT
#define DEF_CAT

#include <string>

class Cat
{
private:
    int size;
    int **shape;
    int iterator_grid_position_x;
    int iterator_grid_position_y;
    int iterator_rotation;
public:
    Cat(int size);
    ~Cat();
    void Set_matrix(std::string values);
    void print_matrix();
    bool place_cat(int ** game_grid,int grid_size);
};

#endif