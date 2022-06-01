#include <iostream>

using namespace std;

////////////////////////////
//   Реализация списка    //
//  Представлен в виде    //
// многофайлового проекта //
// в Discret_labs3_var_6  //
////////////////////////////

template <typename T>
class ListTemplate
{
public:
    ListTemplate();
    void push_back(T data);
    void pop_front(); //удаление первого эл-нта списка
    void display();
    int get_Size() { return Size; }
    T& operator[] (const int index);
    ~ListTemplate();

private:
    template <typename T>
    class Element
    {
    public:
        Element* ptr_next; //хранение адреса на следующий элемент списка
        T data; //значение элемента

        Element(T data = T(), Element* ptr = nullptr)
        {
            this->data = data; //вписываем значение для нового элемента 
            ptr_next = ptr; //
        }
    };

    Element <int> *first; //указатель на первый элемент списка
    int Size; //переменная размера списка, которая самостоятельно инкрементируется при 
              //добавлении нового эл-нта через метод push_back()
};

template <typename T>   
ListTemplate<T>::ListTemplate()
{
    Size = 0;
    first = nullptr;
}

template<typename T>
void ListTemplate<T>::push_back(T data)
{
    if (first == nullptr)
    {
        first = new Element<T>(data); //указатель на первый эл. списка запоминает адрес созданного контейнера
        Size++;
    }
    else
    {
        //с помощью указателя передвигаемся по эл-нтам списка
        Element<T>* current = first; //создаем указатель, указывающий на начальный элемент списка 

        while (current->ptr_next != nullptr) //если в данном элементе указатель на следующий элемент не равен nullpt
        {
            current = (*current).ptr_next; //запоминаем этот адрес на следющий эл.списка и проверяем не явл.ли он последним(не равне ли nullptr)
        }
        //выходим из цикла, когда дошли до последнего элемента списка(т.е. его указатель указывает на nullptr)
        current->ptr_next = new Element <T>(data); //создаем новый эл.списка и присваиваем указателю предыдущего элемента адрес на новый контейнер
        Size++;
    }
}

template<typename T>
void ListTemplate<T>::pop_front() //удаление первого эл-нта списка
{
    Element<T>* temp = first;
    first = first->ptr_next;
    delete temp;
    Size--;
}

template<typename T>
void ListTemplate<T>::display()
{
    Element<T>* current = first;//с помощью указателя передвигаемся по эл-нтам списка
    int index = 0;
    std::cout << "-----------Display-----------" << std::endl;
    while (current != nullptr)
    {
        std::cout << "List[" << index << "]= " << current->data << std::endl;
        index++;
        current = current->ptr_next;
    }
    std::cout << "-----------------------------" << std::endl;
}

template<typename T>
T& ListTemplate<T>::operator[](const int index)
{
    int counter = 0; //счетчик, по скольким элементам мы пробежались
    Element <T>* current = first; //указатель на первый элемент списка
    while (true) //другими словами бегаем бесконечно 
    {
        if (counter == index) //как только оказываемся в контейнере, индекс которого сопадает с требуемым индексом 
        {
            return current->data; //возвращаем значение
        }
        current = current->ptr_next;
            //если еще не дошли до нужного контейнера, присваиваем текущему указателю адрес на след. контейнер
        counter++; //прибавляем счетчик индексации, в каком по счету контейнере находимся
    }
}

template <typename T>
ListTemplate<T>::~ListTemplate()
{

}

void start_list_class_template()
{
    setlocale(LC_ALL, "rus");
    ListTemplate<int> lst;

    int size; 
    cin >> size;//выбираем размер будущющего списка

    for (int i = 0; i < size; i++)//ввод значений элементам списка 
    {
        lst.push_back(rand() % 10); 
    }

    /*lst.push_back(7);
    lst.push_back(10);
    lst.push_back(22);
    lst.push_back(45);*/

    cout << "Список состоит из " << lst.get_Size() << " элементов" << endl;


    for (int i = 0; i < lst.get_Size(); i++)//вывод значений у элементов списка 
    {
        cout << lst[i] << "\t";
    }
    cout << endl;
    lst.pop_front();
    cout << "Убрали первый эл-нт списка" << endl;

    cout << "Список состоит из " << lst.get_Size() << " элементов" << endl;
    for (int i = 0; i < lst.get_Size(); i++)//вывод значений у элементов списка 
    {
        cout << lst[i] << "\t";
    }
    cout << endl;
    lst.display();

}




