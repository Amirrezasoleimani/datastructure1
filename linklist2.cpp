#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
	Node* prev;
	Node(int data)
	{
		this->data = data;
		next = nullptr;
		prev = nullptr;
	}

};
class LinkedList2
{
public:
	Node* head;
	LinkedList2()
	{
		head = nullptr;
	}


	void Display() 
	{
		Node* temp = head;
		cout << "\nNull<-";
		while(temp != nullptr)
		{
			cout << temp->data << "->";
			temp = temp->next;
		}
		cout << "->Null\n";
	}

	void InsertAtIndex(int data, int index)
	{
		if (index < 0)
		{
			cout << "index is not correct\n";
			return;
		}

		Node* item = new Node(data);
		if (index == 0)
		{
			item->next = head;
			item->prev = nullptr;
			head = item;
			return;
		}

		Node* temp = head;
		for (int i = 0; i < index - 1 && temp; i++)
		{
			temp = temp->next;
		}

		if (!temp)
		{
			cout << "index does not exist\n";
			return;
		}
		Node* key;
		item->next = temp->next;
		temp->next = item;
		key = item->next->next;
		item->next->prev = item;
		item->prev = key;

	}


	void InsertAtEnd(int data)
	{
		Node* item = new Node(data);

		if (!head)
		{
			head = item;
			return;
		}
		Node* temp = head;
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = item;
		item->prev = temp;
	}


	void InsertAtFirst(int data)
	{
		Node* item = new Node(data);

		if (!head)
		{
			head = item;
			return;
		}

		Node* temp = head;
		item->next = temp;
		temp->prev = item;
		head = item;
	}


	void UpdateNode(int data, int index)
	{
		if (!head) {
			cout << "List is empty\n";
			return;
		}
		if (index < 0) {
			cout << "Index is not correct\n";
			return;
		}

		Node* temp = head;
		for (int i = 0; i < index && temp; ++i)
		{
			temp = temp->next;
		}

		if (!temp)
		{
			cout << "Index does not exist\n";
			return;
		}

		temp->data = data;
	}


	int RemoveNodeAtIndex(int index)
	{
		if (!head) {
			cout << "List is empty\n";
			return -1;
		}

		if (index < 0) {
			cout << "index is not correct\n";
			return -1;
		}

		Node* temp = head;
		if (index == 0)
		{
			int x = temp->data;
			temp = temp->next;
			temp->prev = nullptr;
			head = temp;
			return x;

		}

		for (int i = 0; i < index  && temp; ++i)
		{
			temp = temp->next;
		}

		if (index >= SizeOfList() || !temp)
		{
			cout << "index does not exist\n";
			return -1;
		}

		int x = temp->data;
		Node* q = temp->prev;
		temp->prev->next = temp->next;
		temp->next->prev = q;
		return x;
	}


	int SizeOfList()
	{
		int count = 0;
		Node* temp = head;
		while (temp != nullptr)
		{
			temp = temp->next;
			count++;
		}
		return count;
	}


	int RemoveNodeAtBegin()
	{
		if (!head)
		{
			cout << "list is empty\n";
			return -1;
		}
		Node* temp = head;
		int x = temp->data;
		head = temp->next;
		return x;
	}


	int RemoveNodeAtEnd()
	{
		if (!head)
		{
			cout << "List is empty." << endl;
			return -1;
		}

		if (!head->next)
		{
			head = nullptr;
			return -1;
		}

		Node* temp = head;
		for (int i = 0; i < SizeOfList() - 2; i++)
		{
			temp = temp->next;
		}
		int x = temp->next->data;
		temp->next = nullptr;
		return x;
	}


	void Concatenate(LinkedList2 newlist)
	{
		if (!newlist.head)
		{
			cout << "newlist is empty\n";
			return;
		}

		if (!head)
		{
			head = newlist.head;
			return;
		}

		Node* temp = head;
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = newlist.head;
		newlist.head->prev = temp;
	}


	void Invert()
	{
		Node* back = head;
		Node* front = head;
		while (back->next)
		{
			back = back->next;
		}
		int temple;
		int i = 1;
		while (i <= SizeOfList() / 2)
		{
			temple = front->data;
			front->data = back->data;
			back->data = temple;
			back = back->prev;
			front = front->next;
			i++;
		}
	}
};
int main()
{
	LinkedList2 a;
	a.InsertAtFirst(98);
	a.InsertAtFirst(99);
	a.InsertAtFirst(87);
	a.InsertAtEnd(665);
	cout << a.SizeOfList();
	a.Display();
	a.UpdateNode(7, 2);
	a.Display();
	a.RemoveNodeAtIndex(2);
	a.Display();
	a.RemoveNodeAtEnd();
	a.Display();
	LinkedList2 b;
	b.InsertAtFirst(43);
	b.Concatenate(a);
	b.InsertAtEnd(5456);
	b.Display();
	b.Invert();
	b.Display();
}

