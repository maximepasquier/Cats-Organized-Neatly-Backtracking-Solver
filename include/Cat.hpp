#ifndef DEF_CAT
#define DEF_CAT

#include <string>

class Cat
{
private:
    int size;
    int **shape;
public:
    Cat(int size);
    ~Cat();
    void Set_matrix(std::string values);
    void print_matrix();
};

#endif