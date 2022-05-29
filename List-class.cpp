#include <iostream>

//����������� �������� ������
//Single linked lineary list

class Node
{
	//��� ���� �������
	Node* next;
	int field;

	//� ������ ������� ������ ����� �������� ������ ����� ������
	friend class List;
};

class List
{
private:
	Node* head; //��������� �� ������ ������
	int count; //���-�� ����� ������

public:
	List()
	{
		head = nullptr;
		count = 0;
	}
	
	//�������� ������ ������ �� �������//
	void add(int, Node*);
	void print();
	void clear();

	//��������������� ������, ������� ����� ���� ������� � ��������� ���������//
	bool isEmpty() { return head == nullptr; } //����������, ���� �� ������
	int getCount() { return count; } //���������� ���-�� ����� � ������
	int getValue(Node* node) { return node->field; } //���������� �������� ����
	void setValue(int data, Node* node) { node->field = data; } //����������� �������� 
	//������������� ����
	Node* next(Node* node) { return node->next; } //���������� ����� ����.����, ������� �� ����������
	Node* previous(Node*); //���������� ����� ��������.����, �������� ����� ����������
	Node* del(Node*); //������� ���������� ����� ���� �� ������ � �������. ��������. ����
	Node* getFirst() { return head; } //���������� ����� ����� ������
	Node* getLast(); //���������� ����� ���������� ���� ������
	void swap(Node*, Node*); //������ ������� ��� ���������� ���� � ������
};

void List::add(int data, Node* node = nullptr)
{

	if (node == nullptr) //���� ���������� ����� - nullptr, ��������� ���� � ������
	{
		if (isEmpty()) //���� ����� ��� - ��������� ����� � ������
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
	else //��������� ����� ���� ����� ���������� node
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
	using std::cout; //using-���������
	using std::endl;

	if (isEmpty()) //���� ������ ���� - ������ ��������
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
		//forDel = current = current->next; ����� ���������� � ������������� ������, ��� �����������: while (current != nullptr)
		delete forDel;
	}
	count = 0;
	head = nullptr; //������ ��� ������������� ������ �� ����������� ��������� nullptr
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

	//���� node1 - ������ ������, � �� ��� ���� �� ������� node2 
	if (node1 == head && node1->next == node2) 
	{
		head = node2;
		node1->next = node2->next; //node1 -> node3 
		node2->next = node1;	   //node2 -> node1 ����� node2 -> node1 -> node3
		return;
	}

	//���� ���������� ���� - ������ ����-����� 
	if (node1->next == node2)
	{
		Node* prevNode1, *current = head;
		while (current->next != node1)
			current = current->next;

		prevNode1 = current;
		current = current->next; //current ������ ��������� �� node1 
		prevNode1->next = node2; //node0 -> node2
		current->next = node2->next; //node1 -> node3
		node2->next = current;   //node2 -> node1, ����� node0 -> node2 -> node1
		

	}
	
	//���� ������ ���� �� ������ ����-�����
	if (node1 == head)
	{
		Node *prevNode2, *current = head;
		while (current->next != node2)
			current = current->next;

		prevNode2 = current;
		current = current->next; //current ������ ��������� �� node2

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
	list.add(5); //������ ������
	list.add(4); //����� ������ ������
	list.add(6, list.getLast()); //����, ������������� ����� �������� ���������� �������� ������
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