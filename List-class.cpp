#include <iostream>

//Односвязный линейный Список
//Single linked lineary list

class Node
{
	//все поля закрыты
	Node* next;
	int field;

	//с полями данного класса может работать только класс списка
	friend class List;
};

class List
{
private:
	Node* head; //указатель на корень списка
	int count; //кол-во узлов списка

public:
	List()
	{
		head = nullptr;
		count = 0;
	}
	
	//Основные методы работы со списком//
	void add(int, Node*);
	void print();
	void clear();

	//Вспомогательные методы, которые могут быть полезны в некоторых ситуациях//
	bool isEmpty() { return head == nullptr; } //возвращает, пуст ли список
	int getCount() { return count; } //возвращает кол-во узлов в списке
	int getValue(Node* node) { return node->field; } //возвращает значение узла
	void setValue(int data, Node* node) { node->field = data; } //присваивает значение 
	//определенному узлу
	Node* next(Node* node) { return node->next; } //возвращает адрес след.узла, стоящий за переданным
	Node* previous(Node*); //возвращает адрес предыдущ.узла, стоящего перед переданным
	Node* del(Node*); //удаляет переданный адрес узла из списка и возвращ. предыдущ. узел
	Node* getFirst() { return head; } //возвращает адрес корня списка
	Node* getLast(); //возвращает адрес последнего узла списка
	void swap(Node*, Node*); //меняет местами два переданных узла в списке
};

void List::add(int data, Node* node = nullptr)
{

	if (node == nullptr) //если переданный адрес - nullptr, добавляем узел в корень
	{
		if (isEmpty()) //если корня нет - добавляем сразу в корень
		{
			head = new Node;
			head->field = data;
			head->next = nullptr;
		}
		else 
		{
			Node* ptr = new Node;
			ptr->field = data;
			ptr->next = head;
			head = ptr;
		}
	}
	else //добавляем новый узел после полученной node
	{
		Node* ptr = new Node;
		ptr->field = data;
		
		Node* current = head;
		while (current != node)
			current = current->next;

		ptr->next = current->next;
		current->next = ptr;
	}
	count++;
}

void List::print()
{
	using std::cout; //using-директива
	using std::endl;

	if (isEmpty()) //если список пуст - нечего выводить
		return;

	Node* current = head;
	int i = 0;
	while (current != nullptr)
	{
		cout << "[" << i++ << "] = " << current->field << endl;
		current = current->next;
	}
}

void List::clear()
{
	if (isEmpty())
		return;

	Node* current = head;
	Node* forDel;
	while (current != nullptr)
	{
		forDel = current;
		current = current->next;
		//forDel = current = current->next; иначе обращаемся к освобожденной памяти, что недопустимо: while (current != nullptr)
		delete forDel;
	}
	count = 0;
	head = nullptr; //потому что высвобождение памяти не присваивает указателю nullptr
}

Node* List::previous(Node* node)
{
	if (isEmpty())
		return nullptr;

	Node* current = head;
	while (current->next != node)
		current = current->next;

	return current;
}

Node* List::del(Node* node)
{
	if (isEmpty())
		return nullptr;

	Node* current = head;
	while (current->next != node)
		current = current->next;

	current->next = current->next->next;
	delete node;
	return current;
}

Node* List::getLast()
{
	if (isEmpty())
		return nullptr;

	Node* current = head;
	while (current->next != nullptr)
		current = current->next;
	return current;
}

void List::swap(Node* node1, Node* node2)
{
	if (isEmpty())
		return;

	if (node1 == nullptr || node2 == nullptr)
		return;

	if (node1 == node2)
		return;

	//если node1 - корень списка, и за ним сраз же следует node2 
	if (node1 == head && node1->next == node2) 
	{
		head = node2;
		node1->next = node2->next; //node1 -> node3 
		node2->next = node1;	   //node2 -> node1 итого node2 -> node1 -> node3
		return;
	}

	//если переданные узлы - соседи друг-другу 
	if (node1->next == node2)
	{
		Node* prevNode1, *current = head;
		while (current->next != node1)
			current = current->next;

		prevNode1 = current;
		current = current->next; //current теперь указывает на node1 
		prevNode1->next = node2; //node0 -> node2
		current->next = node2->next; //node1 -> node3
		node2->next = current;   //node2 -> node1, итого node0 -> node2 -> node1
		

	}
	
	//если данные узлы не соседи друг-другу
	if (node1 == head)
	{
		Node *prevNode2, *current = head;
		while (current->next != node2)
			current = current->next;

		prevNode2 = current;
		current = current->next; //current теперь указывает на node2

		head = current;			 //head -> node2 
		prevNode2->next = node1;
		Node* temp = node1->next;
		node1->next = node2->next;
		head->next = temp;	
	}
	else
	{
		Node* current = head, *prevNode1, *prevNode2;
		while (current->next != node1)
			current = current->next;

		prevNode1 = current;
		while (current->next != node2)
			current = current->next;

		prevNode2 = current;
		
		prevNode2->next = node1;
		Node* temp = node1->next;
		node1->next = node2->next;
		prevNode1->next = node2;
		node2->next = temp;
	}
}

void start_list_class()
{
	List list;
	list.add(5); //корень списка
	list.add(4); //новый корень списка
	list.add(6, list.getLast()); //узел, вставляющийся после текущего последнего элемента списка
	list.add(7, list.getLast());

	list.swap(list.next(list.getFirst()), list.getLast());

	list.print();
	list.del(list.previous(list.getLast()));
	list.print();

	/*list.clear();
	list.print();
	std::cout << "All memory has been freed by the OS" << std::endl;*/
	std::cout << std::endl << list.getValue(list.next(list.previous(list.getLast())));
}
