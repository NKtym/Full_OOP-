#include <iostream>

int main()
{
    int* rat = new int[10];
    delete[] rat;
    return 0;
}