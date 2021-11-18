#include "functions.hpp"

void compute_weight_of_all_cats(Cat *cat_array[], int number_of_cats)
{
    for (size_t i = 0; i < number_of_cats; i++)
    {
        cat_array[i]->compute_cat_weight();
    }
}

void greedy_stochastic(int **padded_game_grid, int padded_grid_size, int grid_size, Cat *cat_array[], int number_of_cats)
{
    //* Commencer avec les plus gros chats (greedy)
    int biggest_cat = cat_array[0]->get_weight();
    int cat_index = 0;
    for (size_t i = 0; i < number_of_cats; i++)
    {
        //+ Cat available
        if (!cat_array[i]->get_availability())
        {
            //+ if bigger cat
            if (cat_array[i]->get_weight() > biggest_cat)
            {
                biggest_cat = cat_array[i]->get_weight();
                cat_index = i;
            }
        }
    }
}