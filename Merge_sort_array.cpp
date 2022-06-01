#include <iostream>

using namespace std;

const int SIZE = 5;

void merg(int arr[], int left, int right)
{
	int i = left; //дл€ интерации по левой последовательности 
	int middle = left + (right - left) / 2;
	int j = middle + 1; //дл€ интерации по правой последовательности 
	int t = 0; //счЄтчик дл€ arrMerged
	int arrMerged[SIZE]; //сливаем элементы из разных последовательностей 

	while (i <= middle && j <= right) 
	{

		if (arr[i] <= arr[j]) 
		{
			arrMerged[t] = arr[i]; 
			i++;
		}
		else 
		{
			arrMerged[t] = arr[j]; 
			j++;
		}
		t++;
	}

	while (i <= middle) 
	{
		arrMerged[t] = arr[i]; 
		i++; 
		t++;
	}

	while (j <= right) 
	{
		arrMerged[t] = arr[j]; 
		j++; 
		t++;
	}

	for (i = 0; i < t; i++)
		arr[left + i] = arrMerged[i];
}
//							 0			2
void mergSort(int* arr, int left, int right)
{
	if (left < right) ///если в последовательности 1 элемент 
		if (right - left == 1) //если в последовательности 2 элемента
		{
			if (arr[left] > arr[right]) 
			{
				int temp = arr[left];
				arr[left] = arr[right];
				arr[right] = temp;
			}
		}
		else 
		{
			int middle = (left + right) / 2;

			mergSort(arr, left, middle);
			mergSort(arr, middle + 1, right);

			merg(arr, left, right);
		}

}

//void input(int* m, int& amp; n)
//{
//
//	cout& lt; &lt; &quot; ¬ведите количество элементов массива& quot;;
//	cin& gt; &gt; n;
//	for (int i = 0; i & lt; n; i++)
//	{
//		cout& lt; &lt; &quot; a[&quot; &lt; &lt; i& lt; &lt; &quot; ] = &quot;;
//
//		cin& gt; &gt; m[i];
//	}
//
//}

static void display_arr(int* arr)
{
	for (int i = 0; i < SIZE; i++)
	{
		std::cout << arr[i] << "\t";
	}
	std::cout << std::endl;
}

void start_merge_sort()
{
	// 4 2 1

	int arr[SIZE] = { 8, 2, 1, 7, 3 };
	display_arr(arr); 
	mergSort(arr, 0, SIZE - 1);
	display_arr(arr); //(-trash) 1 2 3 8 
}