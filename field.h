#ifndef FIELD_H
#define FIELD_H

#include <vector>
#include <algorithm>

enum Direction
{
    lft,
    rght,
    up,
    down
};

class Field
{
private:
    std::vector<int> field;
    void swapHelper(int row, int col,Direction dir);
public:
    Field();
    ~Field();
    void initNew();
    std::vector<int> getField() const;


    static const int SIZE = 16;

    void swap(Direction dir);
    bool win() const;

};

#endif // FIELD_H
