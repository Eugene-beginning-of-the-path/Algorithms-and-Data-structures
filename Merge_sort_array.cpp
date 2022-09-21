#include <iostream>

using namespace std;

const int SIZE = 5;

void Merge(int arr[], int left, int right)
{
	int i = left; //��� ��������� �� ����� ������������������ 
	int middle = left + (right - left) / 2;
	int j = middle + 1; //��� ��������� �� ������ ������������������ 
	int t = 0; //������� ��� arrMerged
	int arrMerged[SIZE]; //������� �������� �� ������ ������������������� 

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
void Sort(int* arr, int left, int right)
{
	if (left < right) ///���� � ������������������ ���� �� 2 �������� � ������ (��� 1 ��-��� �� �������)
		if (right - left == 1) //���� � ������������������ ����� 2 ��������
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

			Sort(arr, left, middle);
			Sort(arr, middle + 1, right);

			Merge(arr, left, right);
		}

}

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
	

	int arr[SIZE] = { 8, 2, 1, 7, 3 };
	display_arr(arr); 
	Sort(arr, 0, SIZE - 1);
	display_arr(arr); 
}