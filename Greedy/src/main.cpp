#include "file_functions.hpp"
#include "functions.hpp"
#include "stdout.hpp"
#include "Cat.hpp"

int main()
{
    //* Main variables
    int grid_size, number_of_different_cats, cats_size, number_of_cats;
    std::vector<std::string> cats_list;
    //* Read game config file
    read_game_config_file("./data/Game_config.txt", grid_size, number_of_different_cats, cats_size, number_of_cats, cats_list);
    //+ Print config infos
    print_config_infos(grid_size, number_of_different_cats, cats_size, number_of_cats, cats_list);
    //* Init and read grid file
    int **game_grid = new int *[grid_size];
    for (size_t i = 0; i < grid_size; i++)
    {
        game_grid[i] = new int[grid_size];
    }
    read_game_grid_file("./data/Grid.txt", game_grid, grid_size);
    print_matrix(game_grid, grid_size);
    //* Init and read cats file
    Cat *cat_array[number_of_cats];
    for (size_t i = 0; i < number_of_cats; i++)
    {
        cat_array[i] = new Cat(cats_size);
    }
    get_cats_shapes("./data/Cats.txt", cat_array, cats_list);
    compute_weight_of_all_cats(cat_array, number_of_cats);
    print_all_cats(cat_array, number_of_cats);

    //* Create a padded game grid
    int padding = cats_size - 1;
    int padded_grid_size = grid_size + 2 * padding;
    int **padded_game_grid = new int *[padded_grid_size];
    for (size_t i = 0; i < padded_grid_size; i++)
    {
        padded_game_grid[i] = new int[padded_grid_size];
    }

    //* Set padding matrix to 1
    for (size_t i = 0; i < padded_grid_size; i++)
    {
        for (size_t j = 0; j < padded_grid_size; j++)
        {
            padded_game_grid[i][j] = 1;
        }
    }

    //* Insert game_gird in padded_game_grid
    for (size_t i = 0; i < grid_size; i++)
    {
        for (size_t j = 0; j < grid_size; j++)
        {
            padded_game_grid[i + padding][j + padding] = game_grid[i][j];
        }
    }

    print_matrix(padded_game_grid, padded_grid_size);

    greedy_stochastic(padded_game_grid, padded_grid_size, grid_size, cat_array, number_of_cats);

    return 0;
}
