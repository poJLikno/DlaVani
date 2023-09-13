#include <iostream>

#define y_val 4
#define x_val 6

int main(int argc, const char * argv[])
{
    int island_count = 0;
    
    int array[y_val][x_val] = {
        {1, 1, 0, 1, 0, 1},
        {1, 0, 0, 0, 1, 1},
        {0, 1, 1, 0, 0, 0},
        {0, 0, 1, 0, 1, 1}
    };
    
    for (int i = 0; i < y_val; ++i)
    {
        for (int j = 0; j < x_val; ++j)
        {
            if (array[i][j]
                && (i - 1 >= 0 ? !array[i - 1][j] : 1)
                && (j - 1 >= 0 ? !array[i][j - 1] : 1))
            {
                ++island_count;
            }
        }
    }
    
    std::cout << island_count << "\r\n";
    
    return 0;
}
