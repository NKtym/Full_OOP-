#include <iostream>
#include <time.h>

int* genRandArray(int size, int maxValue)
{
    int* array = new int[size+1];
    array[0] = size;
    for (int i = 0; i < size; i++)
    {
        array[i+1] = rand()%maxValue;
    }
    return array;
}

void print(int* arr)
{
    std::cout<<arr[0]<<": ";
    for (int i = 0; i < arr[0]; i++)
    {
        std::cout<<arr[i+1]<<' ';
    }
    std::cout<<'\n';
}

int main()
{
    srand(time(NULL));
    int size = rand()%10;
    int maxValue = 100;
    int* arr = genRandArray(size, maxValue);
    print(arr);
    delete(arr);
    return 0;
}
