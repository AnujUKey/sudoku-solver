#include <iostream>

int main()
{
    int row;
    int col;
    int digit;
    
    // for(int i = 0; i < 81; i++)
    // {
    //     std::cout << "column for digit constraints: ";
    //     std::cout << i << std::endl;
        
    //     for(int j = 0; j < 9; j++)
    //     {
    //         row = i / 9;
    //         col = i % 9;
    //         digit = j + 1;
    //         std::cout << " r: " << row;
    //         std::cout << " c: " << col;
    //         std::cout << " #: " << digit << std::endl;
    //     }
    // }

    // for(int i = 0; i < 81; i++)
    // {
    //     std::cout << "column for row constraints: ";
    //     std::cout << i << std::endl;
        
    //     for(int j = 0; j < 9; j++)
    //     {
    //         row = i / 9;
    //         col = j;
    //         digit = (i % 9) + 1;
    //         std::cout << " r: " << row;
    //         std::cout << " c: " << col;
    //         std::cout << " #: " << digit << std::endl;
    //     }
    // }

    // for(int i = 0; i < 81; i++)
    // {
    //     std::cout << "column for column constraints: ";
    //     std::cout << i << std::endl;
        
    //     for(int j = 0; j < 9; j++)
    //     {
    //         row = j;
    //         col = i / 9;
    //         digit = (i % 9) + 1;
    //         std::cout << " r: " << row;
    //         std::cout << " c: " << col;
    //         std::cout << " #: " << digit << std::endl;
    //     }
    // }
    
    for(int i = 0; i < 81; i++)
    {
        std::cout << "column for box constraints: ";
        std::cout << i << std::endl;
        
        for(int j = 0; j < 9; j++)
        {
            if((i % 9) < 3)
            {
                row = (j / 3);
            }
            else if((i % 9) < 6)
            {
                row = (j / 3) + 3;
            }
            else
            {
                row = (j / 3) + 6;
            }

            if(row < 3)
            {
                col = j % 3;
            }
            else if(row < 6)
            {
                col = (j % 3) + 3;
            }
            else
            {
                col = (j % 3) + 6;
            }
            digit = (i % 9) + 1;
            std::cout << " r: " << row;
            std::cout << " c: " << col;
            std::cout << " #: " << digit << std::endl;
        }
    }

    return 0;
}