#include <iostream>

////////////////////////////////////////////////////////////////////
// Демонстрация метода сортировки вставкой целочисленного массива // 
////////////////////////////////////////////////////////////////////

const int SIZE = 5;

void insert_sort(int* arr)
{
	for (int i = 1; i < SIZE; i++)
	{
		int j = i;
		while (j > 0 && arr[j - 1] > arr[j])
		{
			int temp = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = temp;
			j--;
		}
	}
}

void display_arr(int* arr)
{
	for (int i = 0; i < SIZE; i++)
	{
		std::cout << arr[i] << "\t";
	}
}

void start_insert_sort()
{
	int arr[SIZE] = {4, 3, 5, 1, 2};

	insert_sort(arr);
	display_arr(arr);
}