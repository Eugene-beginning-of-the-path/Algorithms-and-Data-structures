#include <iostream>
#include <typeinfo>

using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////
// Демонстрация метода сортировки массива(arr) указателей на динамические объекты класса Person,// 
// который имеет поле name(string). Метод сортирует данный массив по значениям поля name каждого//
// из объектов класса данного массива по возрастанию значений из таблицы ASCII					//
//////////////////////////////////////////////////////////////////////////////////////////////////

//Важно!: Person* arr[5] - тип данных **, т.к. arr-указатель, и Person* - указатель = 
//вложенные указатель **, поэтому тип параметров функции, принимающих этот массив должны иметь
//тип Person** ptr, либо Person* arr[n]

class Person
{
public:
	string name;

	Person(string name)
	{
		this->name = name;
	}

	void show()
	{
		std::cout << name;
	}

	void change_name()
	{
		std::cin >> name;
	}
};

void start_bubble_sort()
{


	Person* arr[3]; //arr массив - указатель на первый эл-нт, Person* arr[5] - вложенный указатель

	for (int i = 0; i < 3; i++)
	{
		string name;
		std::cin >> name;
		arr[i] = new Person(name);
	}

	void show_names(Person * arr[3]);
	void bubble_sort(Person * ptr[3]);
	show_names(arr);
	bubble_sort(arr);
	show_names(arr);
}

void show_names(Person* arr[3])
{
	std::cout << "Show names: ";
	for (int i = 0; i < 3; i++)
	{
		arr[i]->show();
		std::cout << "\t";
	}
}

void bubble_sort(Person* ptr[3])
{
	for (int i = 0; i < 2; i++)
		for (int j = i + 1; j < 3; j++)
		{
			if ((*ptr[i]).name > (*ptr[j]).name)
			{
				Person* temp = ptr[i];
				ptr[i] = ptr[j];
				ptr[j] = temp;
			}
		}
}