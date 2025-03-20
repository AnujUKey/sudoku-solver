#include <memory>
#include <iostream>

typedef struct node
{
    int r; // row number
    int c; // column number
    int d; // digit from 1-9
    
    node *up, *down, *left, *right;
} node;

typedef struct columnHeader // special nodes for the column headers
{
    int numNodes = 9; // each column header will always start with have 9 nodes in their column for a 9x9 sudoku game
    char constraint;
    node *first;
    node *last; // last node in column
    columnHeader *left, *right;
} columnHeader;

// typedef struct dlx // this will store the sparse matrix
// {
//     vector<columnHeader> columns;
// } dlx;


/*
dlx matrix layout 729 x 324, 2916 + 1 nodes
            row-col (d) | row (r) | col (c) | box (b)  81 + 81 + 81 + 81
9^3
row col #
1   1   1   
1   1   2   

.   .   . 

1   1   9
1   2   1

.   .   . 

1   9   9
2   1   1

.   .   . 

3   1   1
.   .   . 

9   9   9
*/

void initConstraintCols(char c, columnHeader *end)
{
    for(int i = 0; i < 81; i++)
    {
        columnHeader *col = new columnHeader;
        col->constraint = c;
        for(int j = 0; j < 9; j++)
        {
            node *nd = new node;
            switch (c)
            {
                case 'd': // digit
                    nd->r = i / 9;
                    nd->c = i % 9;
                    nd->d = j + 1;
                    break;

                case 'r': // row
                    nd->r = i / 9;
                    nd->c = j;
                    nd->d = (i % 9) + 1;
                    break;

                case 'c': // column
                    nd->r = j;
                    nd->c = i / 9;
                    nd->d = (i % 9) + 1;
                    break;

                case 'b': // box
                    if((i % 9) < 3)
                    {
                        nd->r = (j / 3);
                    }
                    else if((i % 9) < 6)
                    {
                        nd->r = (j / 3) + 3;
                    }
                    else
                    {
                        nd->r = (j / 3) + 6;
                    }
                    
                    if(nd->r < 3)
                    {
                        nd->c = j % 3;
                    }
                    else if(nd->r < 6)
                    {
                        nd->c = (j % 3) + 3;
                    }
                    else
                    {
                        nd->c = (j % 3) + 6;
                    }

                    nd->d = (i % 9) + 1;
                    break;

                default:
                    return;
            }

            if(j == 0) {
                col->first = nd;
                nd->up = col->last;
                col->last = nd;
            }
            else
            {
                nd->up = col->last;
                col->last = nd;
            }
        }
        end->right = col;
        col->left = end;
        *end = *col;
    }
}

void initDLX()
{ 
    columnHeader *head = new columnHeader;
    columnHeader *end = head;

    initConstraintCols('d', end);
    initConstraintCols('r', end);
    initConstraintCols('c', end);
    initConstraintCols('b', end);
}

void cover(columnHeader *column)
{

}

void uncover(columnHeader *column)
{

}

/*
after initializing the full matrix, remove constraints and add them to our solution to solve our specific sudoku game
the sudoku game input will be an array of 81 integers, and 0s will be empty cells in the sudoku
*/
void initGame(columnHeader *head)
{
    
}
/*
run knuth's algorithm x on the structure to find all possible solutions
*/
void solve(columnHeader *head)
{

}