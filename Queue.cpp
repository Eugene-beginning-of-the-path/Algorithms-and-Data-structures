#include <iostream>

using namespace std;

const int Max_size = 100;

class Queue
{
    int arr_queue[Max_size];
    int size, put_element, get_element;

public:
    Queue(int value_size)
    {
        if (value_size < 0)
            size = 1;
        else
            if (Max_size < value_size)
                size = 100;

        size = value_size;

        put_element = get_element = 0;
    }

    void put(int value)
    {
        if (put_element == size)
        {
            cout << "Очередь полна, куда суешь значение?" << endl;
            return;
        }
        else
        {
            put_element++;
            arr_queue[put_element] = value;
        }
    }

    int get()
    {
        if (get_element == size)
        {
            cout << "Очередь пуста, мужик" << endl;
            return 0;
        }
        else
        {
            get_element++;
            return arr_queue[get_element];
        }
    }

    int Front()
    {
        if (1 <= size)
        {
            int temp;
            temp = get_element;
            get_element = 0;
            cout << "\n1ый элемент очереди: " << this->get();
            get_element = temp;
            return arr_queue[1];
        }
        else
            cout << "Очередь пуста!" << endl;
    }

    void EnQueue()
    {
        size++;
        int x;
        cout << "Введите значение, которое хотите добавить в конец очереди: ";
        cin >> x;
        this->put(x);
    }

    int Retrive(int number)
    {
        int temp = get_element;
        get_element = number - 1;
        cout << "В очереди под элементом " << get_element << "находится значение: " << this->get();
        int temp1 = this->get();
        get_element = temp;
        return temp1;
    }

    int GetSize() { return size; }
};

void start_queue()
{
    setlocale(LC_ALL, "rus");

    int x;
    cout << "Сколько элементов вы хотите вписать в очередь? Ответ: ";
    cin >> x;

    Queue queue(x);
    cout << "Введите " << x << " элементов в очередь: ";
    for (int i = 0; i < queue.GetSize(); i++)
    {
        int enter;
        cin >> enter;
        queue.put(enter);
    }

    queue.EnQueue();

    cout << "Выведем элементы очереди: ";
    for (int i = 0; i < queue.GetSize(); i++)
    {
        cout << queue.get() << "; ";
    }

    queue.Front();

    int b;
    cout << "\nВведите номер элемента очереди, который хотите вывести на экран: ";
    cin >> b;
    queue.Retrive(b);
}


