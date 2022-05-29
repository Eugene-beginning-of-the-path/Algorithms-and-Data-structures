#include <iostream>

//Big O = (N)
int linear_search(int arr[], const int size, int key)
{
	for (int i = 0; i < size; i++)
	{
		if (key == arr[i])
			return i;
	}
	return -1;
}

static void showArr(int arr[], const int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << "\t";
	}
	std::cout << std::endl;
}

void start_linear_search()
{
	const int size = 15;
	int arr[size];
	int key; //ключ поиска

	for (int i = 0; i < size; i++) //не обязательно в линейном поиске массив должен быть отсортирован
	{
		arr[i] = i + 1;
	}

	std::cout << "Enter a key for search: ";
	std::cin >> key;

	int index = linear_search(arr, size, key);
	if (0 <= index)
		std::cout << "Array has " << key << "; index = " << index << std::endl;
	else
		if (index == -1)
			std::cout << "Array does not have " << key << std::endl;
}