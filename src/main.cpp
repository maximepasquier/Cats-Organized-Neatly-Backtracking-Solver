#include "fct_files.hpp"
#include "Cat.hpp"

int main()
{
    int number_of_different_cats, maximum_cat_shape, number_of_cats, initial_grid_size, padded_grid_size, grid_total_sum = 0;
    std::vector<std::string> list_of_cats;

    get_cats_config("./data/CatsConfig.txt", number_of_different_cats, maximum_cat_shape, number_of_cats, list_of_cats);

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
        cat_array[i]->Set_cat_number(i+1);
    }

    get_cats_shapes("./data/CatsShapes.txt", cat_array, list_of_cats);

    cat_array[0]->print_matrix();
    cat_array[1]->print_matrix();
    cat_array[2]->print_matrix();
    cat_array[3]->print_matrix();
    cat_array[4]->print_matrix();
    cat_array[5]->print_matrix();
    cat_array[6]->print_matrix();
    cat_array[7]->print_matrix();

    get_grid_size("./data/GridConfig.txt", initial_grid_size);

    std::cout << "Gris is of size : " << initial_grid_size << std::endl;

    //* game_grid padding with max cat shape
    padded_grid_size = initial_grid_size + 2 * (maximum_cat_shape - 1);

    std::cout << "Gris is of size (with padding) : " << padded_grid_size << std::endl;

    int **game_grid_padded;
    game_grid_padded = new int *[padded_grid_size];
    for (int i = 0; i < padded_grid_size; i++)
    {
        game_grid_padded[i] = new int[padded_grid_size];
    }

    set_grid_to_1(game_grid_padded, padded_grid_size);

    get_grid("./data/GameGrid.txt", game_grid_padded, padded_grid_size, maximum_cat_shape);

    print_grid(game_grid_padded, padded_grid_size);
    std::cout << std::endl;

    //* Backtracking

    int iterator = 0;
    while (iterator < number_of_cats)
    {
        //std::cout << "L'iterator est : " << iterator << std::endl;

        if (cat_array[iterator]->place_cat(game_grid_padded, padded_grid_size))
        {
            iterator++;
        }
        else
        {
            iterator--;
        }
        //print_grid(game_grid_padded, padded_grid_size);
        //std::cout << std::endl;
    }

    /*
    cat_array[7]->print_matrix();
    cat_array[7]->rotate_shape();
    cat_array[7]->print_matrix();

    
    std::cout << "Solution grid is : " << std::endl;
    */
    print_grid(game_grid_padded, padded_grid_size);
    std::cout << std::endl;

    int **solution_grid;
    solution_grid = new int *[initial_grid_size];
    for (int i = 0; i < initial_grid_size; i++)
    {
        solution_grid[i] = new int[initial_grid_size];
    }
    print_solution(solution_grid, cat_array, initial_grid_size,number_of_cats);

    return 0;
}