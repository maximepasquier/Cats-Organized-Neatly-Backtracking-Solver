#ifndef DEF_CAT
#define DEF_CAT

#include <iostream>
#include <vector>

class Cat
{
private:
    int cat_number;
    int matrix_size;
    int cat_weight;
    int **shape;
    bool already_placed;
public:
    Cat(int size);
    ~Cat();
    void compute_cat_weight();
    void set_matrix(std::string values);
    void print_matrix();
    bool get_availability();
    void set_availability(bool status);
    int get_weight();
    void rotate_shape();
};

#endif