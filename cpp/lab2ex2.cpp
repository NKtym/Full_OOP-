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

int** genRandMatrix(int size, int maxValue)
{
	int size_array;
	int** array = new int*[size];
	for (int i = 0; i < size; i++)
	{
	    size_array = rand()%10;
	    array[i] = genRandArray(size_array, maxValue);
	}
	return array;	
}

void print(int** matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
    	for(int j = 0; j < matrix[i][0]; j++){
            std::cout<<matrix[i][j+1]<<' ';
        }
        std::cout<<'\n';
    }
    std::cout<<'\n';
}

int main()
{
    srand(time(NULL));
    int size = rand()%10;
    int maxValue = 100;
    int** matrix = genRandMatrix(size, maxValue);
    print(matrix, size);
    delete(matrix);
}
