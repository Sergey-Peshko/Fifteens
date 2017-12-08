#include "field.h"

void Field::initNew()
{
    field.clear();
    for (int i = 0; i < SIZE; i++)
    {
        field.push_back(i+1);
    }
    field[15] = -1;
    std::random_shuffle(field.begin(),field.end());
}

std::vector<int> Field::getField() const
{
    return field;
}

void Field::swapHelper(int row, int col, Direction dir)
{
    int cur = 4*row + col;
    int toSwap;
    switch (dir) {
    case lft:
        if (col-1 >= 0) {
            toSwap = 4*row + col-1;
            std::swap(field[cur],field[toSwap]);
        }
        break;
    case rght:
        if (col+1 <= 3) {
            toSwap = 4*row + col+1;
            std::swap(field[cur],field[toSwap]);
        }
        break;
    case up:
        if (row-1 >= 0) {
            toSwap = 4*(row-1) + col;
            std::swap(field[cur],field[toSwap]);
        }
        break;
    case down:
        if (row+1 <= 3) {
            toSwap = 4*(row+1) + col;
            std::swap(field[cur],field[toSwap]);
        }
        break;
    default:
        break;
    }
}

void Field::swap(Direction dir)
{
    std::vector<int>::iterator it = std::find(field.begin(),field.end(),-1); // find empty field
    int n = it - field.begin();
    swapHelper(n/4,n%4,dir);
}

bool Field::win() const
{
    for (int i = 0; i < SIZE-1; i++)
    {
        if (field[i] != i+1) return false;
    }
    return true;
}

Field::Field()
{
    initNew();
}

Field::~Field()
{

}

