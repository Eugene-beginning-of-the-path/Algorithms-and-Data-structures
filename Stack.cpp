#include <iostream>

using namespace std;

const int Max_size = 100;

class Stack
{
    int arr_stack[Max_size];
    int size, put_element, get_element;

public:
    Stack(int value_size)
    {
        if (value_size < 0)
            size = 1;
        else
            if (Max_size < value_size)
                size = 100;
            else
                size = value_size;

        put_element = get_element = 0;
    }

    void put(int value)
    {
        if (put_element == size)
        {
            cout << "Стек переполнен!" << endl;
            return;
        }
        else
        {
            put_element++;
            get_element = put_element + 1;
            arr_stack[put_element] = value;
        }
    }

    int get()
    {
        if (get_element == -1)
        {
            cout << "Стек пуст!" << endl;
            return 0;
        }
        else
        {
            get_element--;
            return arr_stack[get_element];
        }
    }

    int Top()
    {
        get_element = put_element;
        return arr_stack[get_element];
    }

    void Pop()
    {
        size--;
        cout << "\nУдаляем элемент с вершины стека" << endl;
    }

    int Retrive(int number_element)
    {
        if (number_element > size || number_element <= 0)
        {
            cout << "Результат не определен, т.к. этой позиции нет в стеке." << endl;
            return -333333;
        }
        else
        {
            int position = number_element - size;

            if (position == 0)
                position = size - 1;
            else
                if (position < 0)
                    position = -position;

            int i = 0;
            int j = size;
            while (true)
            {
                if (i == position)
                    return arr_stack[j];

                j--;
                i++;
            }
        }

    }

    int GetSize() { return size; }
};

int start_stack()
{
    setlocale(LC_ALL, "rus");

    int x;
    cout << "Сколько элементов вы хотите вписать в стек? Ответ: ";
    cin >> x;

    Stack stack(x);

    if (x < 0)
        cout << "Вы ввели отрицательное значение для размерности стека, теперь размер стека = 1" << endl;
    else
        if (100 < x)
            cout << "Вы ввели значение для размерности стека превышающее 100, теперь размер стека = 100" << endl;


    cout << "Введите " << stack.GetSize() << " элементов в стек: ";
    for (int i = 0; i < stack.GetSize(); i++)
    {
        int enter;
        cin >> enter;
        stack.put(enter);
    }

    cout << "Выведем элементы стека: ";
    for (int i = 0; i < stack.GetSize(); i++)
    {
        cout << stack.get() << "; ";
    }

    cout << "\nЭлемент с вершины стека: " << stack.Top();

    stack.Pop();
    cout << "И снова выведем элементы стека: ";
    for (int i = 0; i < stack.GetSize(); i++)
    {
        cout << stack.get() << "; ";
    }

    int position_element, value_element;
    cout << "\nВведите позицию элемента в стеке, которого хотите вывести на экран: ";
    cin >> position_element;
    value_element = stack.Retrive(position_element);
    if(value_element != -333333)
        cout << "Элемент, находящийся в стеке в позиции " << position_element << " = " << value_element << endl;
    

}


