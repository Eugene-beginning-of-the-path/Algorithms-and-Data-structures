#include <iostream>
using namespace std;

void start_bubble_sort();
void start_insert_sort();
void start_linear_search();
void start_merge_sort();
void start_binary_search();

void main()
{
	start_merge_sort();
}

//void Merge(int A[], int p, int q, int r);
//void Sort(int* A, int p, int r);
//void display_A(int* A, const unsigned size);
//
//void main()
//{
//	int A[] = {5,2,4,6,1,3,2,6};
//	const unsigned size = sizeof(A) / sizeof(A[0]);
//	display_A(A, size);
//	Sort(A, 0, size - 1);
//	display_A(A, size); //result after Sort(): 1 2 2 3 4 5 6 6
//}
//
//void Merge(int A[], int p, int q, int r)
//{
//	int i = p; //для интерации по левой последовательности 
//	int middle = q;
//	int j = middle + 1; //для интерации по правой последовательности 
//	int t = 0; //счётчик для arrMerged
//	//const int size = sizeof(arr) / sizeof(arr[0]);
//	int arrMerged[8]; //сливаем элементы из разных последовательностей 
//
//	while (i <= middle && j <= r)
//	{
//
//		if (A[i] <= A[j])
//		{
//			arrMerged[t] = A[i];
//			i++;
//		}
//		else
//		{
//			arrMerged[t] = A[j];
//			j++;
//		}
//		t++;
//	}
//
//	while (i <= middle)
//	{
//		arrMerged[t] = A[i];
//		i++;
//		t++;
//	}
//
//	while (j <= r)
//	{
//		arrMerged[t] = A[j];
//		j++;
//		t++;
//	}
//
//	for (i = 0; i < t; i++)
//		A[p + i] = arrMerged[i];
//}
//
//void Sort(int* A, int p, int r)
//{
//	if (p < r) ///если в последовательности хотя бы 2 элемента и больше (при 1 эл-нте не пройлет)
//		if (r - p == 1) //если в последовательности ровно 2 элемента
//		{
//			if (A[p] > A[r])
//			{
//				int temp = A[p];
//				A[p] = A[r];
//				A[r] = temp;
//			}
//		}
//		else
//		{
//			int middle = (p + r) / 2;
//
//			Sort(A, p, middle);
//			Sort(A, middle + 1, r);
//
//			Merge(A, p, middle, r);
//		}
//
//}
//
//void display_A(int* A, const unsigned size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		std::cout << A[i] << "\t";
//	}
//	std::cout << std::endl;
//}