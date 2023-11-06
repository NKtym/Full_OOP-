#include <iostream>

int* genRandArray(int size, int maxValue)
{
    	int* array = new int[size];
    	for (int i = 0; i < size; i++)
    	{
    	    array[i] = rand()%maxValue;
    	}
    	return array;
}

int** genRandMatrix(int size, int maxValue)
{
	int** array = new int*[size];
	for (int i = 0; i < size; i++)
	{
	    array[i] = genRandArray(size, maxValue);
	}
	return array;	
}

void print(int** matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
    	for(int j = 0; j < size; j++){
            std::cout<<matrix[i][j]<<' ';
        }
        std::cout<<'\n';
    }
    std::cout<<'\n';
}

int* rightDiagonal(int** matrix, int* arr, int size)
{
	int plus = 0;
	int mines = 1;
	int data = 0;
	int dat = 0;
	for(int i=0; i < size; i++){
		while(plus < size - dat){
			arr[data] = matrix[i+plus][size-mines];
			plus++;
			mines++;
			data++;
		}
		plus=0;
		mines=1;
		while(plus < size - dat - 1){
			arr[data] = matrix[i-dat+plus][size-mines-dat - 1];
			plus++;
			mines++;
			data++;
		}
		dat++;
		plus=0;
		mines=1;
	}
	
	return arr;
}

int* leftDiagonal(int** matrix, int* arr, int size)
{
	int data = 0;
	int dat = 0;
	for(int i = 0; i < size; i++){
		arr[data] = matrix[i+dat][i];
		data++;
	}
	dat++;
	while(dat < size){
		for(int i = 0 + dat; i < size; i++){
			arr[data] = matrix[i][i-dat];
			data++;
		}
		for(int i = 0 + dat; i < size; i++){
			arr[data] = matrix[i-dat][i];
			data++;
		}
		dat++;
	}
	return arr;
}

int* centerSpiral(int** matrix, int* arr, int size)
{
	if(size == 0){
		return arr;
	}
	if(size == 1){
		arr[0] = matrix[0][0];
		return arr;
	}
	if(size % 2 == 1){
		int j1 = 0;
		int j2 = 0;
		int j3 = 0;
		int j4 = 0;
		int data = 0;
		arr[data] = matrix[size/2][size/2];
		data++;
		while(arr[data-1] != matrix[0][size-1]){
			for(int width = size/2+j1-1; width >= size/2-1-j1 ; width--){
				arr[data] = matrix[size/2-j1][width];
				data++;
			}
			j1++;
			for(int heigh = size/2-j2+1; heigh<=size/2+1+j2; heigh++){
				arr[data] = matrix[heigh][(size/2)-1-j2];
				data++;
			}
			j2++;
			for(int width = size/2-j3; width <= size/2+1+j3; width++){
				arr[data] = matrix[size/2+1+j3][width];
				data++;
			}
			j3++;
			for(int heigh = size/2+j4; heigh >= size/2-1-j4; heigh--){
				arr[data] = matrix[heigh][size/2+1+j4];
				data++;
			}
			j4++;	
		}
		for(int i = size-2; i >= 0; i--){
			arr[data] = matrix[0][i];
			data++;
		}
	}
	else{
		//Использую метот постоянных координат перемещая их по диагонали
		int j1 = 0;
		int j2 = 0;
		int j3 = 0;
		int j4 = 0;
		int flag = 0;
		arr[data] = matrix[(size-1)/2+1][(size-1)/2];
		data++;
		while(data < size*size){
			for(int width = (size-1)/2 -j1 + 1; width<=(size-1)/2+j1+1; width++){//+ 1 потому что иначе не доходит до конца
				arr[data] = matrix[((size-1)/2+1+j1)][width];
				data++;
			}
			j1++;
			for(int heigh = (size-1)/2+j2; heigh>=(size-1)/2-j2; heigh--){
				arr[data] = matrix[heigh][(size - 1)/2+j2+1];
				data++;
			}
			j2++;
			for(int width = (size-1)/2+j3; width>=(size-1)/2-j3-1;width--){
				arr[data] = matrix[(size-1)/2-j3][width];
				if(arr[data] == matrix[0][0]){
					flag = 1;
					break;
				}
				data++;
			}
			if(flag){
				break;
			}
			j3++;
			for(int heigh = (size-1)/2+1-j4; heigh<=(size-1)/2+2+j4; heigh++){ 
				arr[data] = matrix[heigh][(size - 1)/2-1-j4];
				data++;
			}
			j4++;
		}
	}
	return arr;
}

int* leftSpiral(int** matrix, int* arr, int size)
{
	int width = 0;
	int down_height = 0;
	int up_height = 0;
	int data = 0;
	while(data < size*size){
		for(int i = 0 + width;i<size - width; i++){
			arr[data] = matrix[width][i];
			data++;
		}
		width++;
		for(int i = 0 + width; i<size - down_height; i++){
			arr[data] = matrix[i][size-width];
			data++;
		}
		down_height++;
		for(int j = size-width-1; j >= 0 + up_height; j--){
			arr[data] = matrix[size - width][j];
			data++;
		}
		up_height++;
		for(int j = size-down_height-1; j >= width; j--){
			arr[data] = matrix[j][width-1];
			data++;
		}
	}
	return arr;
}

void printArr(int* arr, int size){
	std::cout<<'\n';
	for(int i = 0; i<size*size; i++){
		std::cout<<arr[i]<<' ';
	}
}

int main(){
	srand(time(NULL));
    	int size = rand()%7;
    	int maxValue = 100;
    	int** matrix = genRandMatrix(size, maxValue);
    	int* arr = new int[size*size];
    	print(matrix, size);
    	leftSpiral(matrix,arr, size);
    	std::cout<<"D)";
 	printArr(arr,size);
 	rightDiagonal(matrix,arr,size);
 	std::cout<<"\nA)";
 	printArr(arr,size);
 	leftDiagonal(matrix,arr,size);
 	std::cout<<"\nB)";
 	printArr(arr,size);
 	std::cout<<"\nC)";
 	centerSpiral(matrix,arr,size);
 	printArr(arr,size);
 	std::cout<<'\n';
 	delete(arr);
    	delete(matrix);
    	return 0;
}
