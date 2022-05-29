#include <iostream>

//Big O = (log N)
int binary_search(int arr[], const int size, int key)
{
	int left = 0, right = size;
	int middle;

	while (1)
	{
		middle = (left + right) / 2;
		
		if (left > right)
			return -1;

		if (arr[middle] < key)
			left = middle + 1;
		else
			if (key < arr[middle])
				right = middle - 1;
			else
				return middle;
	}
}

static void showArr(int arr[], const int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << "\t";
	}
	std::cout << std::endl;
}

void start_binary_search()
{
	const int size = 15;
	int arr[size];
	int key; //ключ поиска

	for (int i = 0; i < size; i++) //обязательно в бинарном поиске массив должен быть отсортирован
	{
		arr[i] = i + 1;
	}

	std::cout << "Enter a key for search: ";
	std::cin >> key;

	int index = binary_search(arr, size, key);
	if (0 <= index)
		std::cout << "Array has " << key << "; index = " << index << std::endl;
	else
		if (index == -1)
			std::cout << "Array does not have " << key << std::endl;
}

