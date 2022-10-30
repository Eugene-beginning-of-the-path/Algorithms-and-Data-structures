#include <iostream>

using namespace std;

void foo()
{
	char arr[3] = "ab";		//автоматом выделяется место под '\0'
	char* arr1 = new char[3];   //не выделяется автоматом место под '\0'
	arr1[0] = 'a';
	arr1[1] = 'b';
	arr1[2] = 'c';
	arr1[3] = '\0';				//никто нас не контролирует и мы можем выйти намеренно
								//за пределы памяти массива, перезаписав чужие данные 

	std::cout << strlen(arr);   //strlen - кол-во считывает символов до '\0'
	std::cout << strlen(arr1);

	char str[] = "G H - g h!";
	char* str1 = new char[strlen(str)];
	int sum = 0;

	for (int i = 0, j = 0; i < strlen(str); i++)
	{
		if (str[i] == ' ')
			continue;

		sum++;	//для подсчета кол-ва символов без пробела
		str1[j++] = str[i];
		if (i == strlen(str) - 1)
			str1[j] = '\0';		//чтобы можно было работать с strlen(str1), т.к.
							    //strlen ориентируется на '\0'
	}
	/*while (*str1)
		std::cout << *str1++;*/ //окончательно сдвинет указатель 
	//std::cout << std::endl << strlen(str1) << std::endl; //и тогда не сможем подсчитать
	//кол-во символов через strlen, т.к. мы будем уже ссылаться указателем на другую часть памяти

	char* str2 = new char[sum];

	for (int i = strlen(str1) - 1, j = 0; i > -1; i--) //здесь i = strlen(str1) - 1, потомучто strlen выдаст нам кол-во символов, но если мы обратимся к индексу [i], то попадем сразу на '\0'
	{
		if (str1[i] != ' ')
			//str2[j--] = str1[i];
			str2[j++] = str1[i];

		if (i == 0)
			str2[j] = '\0';
	}
	

	while (*str2)
		std::cout << *str2++;	//окончательно сдвинули указатель 

	std::cout << '\n';

	while (*str2 != '!')		//сдвигаем указатель обратно на прежнюю позицию
		str2--;

	for (int i = 0; i < strlen(str2); i++)
		std::cout << str2[i];


}

















void start_someWorkWithChar()
{
	foo();
#ifdef DEF
	setlocale(LC_ALL, "rus");
	char str[] = "M T - g d!"; //исходная строка
	int size = strlen(str);						//узнаем ее размер для удобства в циклах
	int sym = 0;								//подсчитаем кол-во символов без пробелов
	char* copyed = new char[size];				//скопируем сюда исходную строку без пробелов

	cout << size << endl;
	for (int i = 0, j = 0; i < size; i++)	   //подсчитываем кол-во пробелов
	{
		if (str[i] == ' ')
			continue;

		sym++;
		copyed[j++] = str[i];				   //и если символ не является пробелом,
											   //копируем его в новую строку
	}
	cout << "Символов в строке(без пробелов): " << sym << endl;
	char* lastest = new char[sym - 1];			   //создадим новый массив, чтобы за ним не 
											   //крепилось больше памяти для пробелов
	for (int i = 0, j = sym - 1; i < sym; i++, j--)
		lastest[j] = copyed[i];
	delete[] copyed;

	for (int i = 0; i < sym; i++)
		cout << lastest[i];
#endif
}