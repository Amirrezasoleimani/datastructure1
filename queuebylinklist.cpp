#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node
{
	int data;
	Node* next;
	Node(int data)
	{
		this->data = data;
		next = nullptr;
	}
};

class LinkedList
{
public:
	Node* head;

	LinkedList()
	{
		head = nullptr;
	}


	void Display()
	{
		Node* temp = head;
		while (temp != nullptr)
		{
			cout << temp->data << "->";
			temp = temp->next;
		}
		cout << "null" << endl;

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
		item->next = temp->next;
		temp->next = item;
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
	}


	void InsertAtFirst(int data)
	{
		Node* item = new Node(data);
		item->next = head;
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
			head = temp->next;
			return x;

		}

		for (int i = 0; i < index - 1 && temp; ++i)
		{
			temp = temp->next;
		}

		if (index >= SizeOfList() || !temp)
		{
			cout << "index does not exist\n";
			return -1;
		}

		int x = temp->next->data;
		temp->next = temp->next->next;
		return x;
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


	void Concatenate(LinkedList newlist)
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
		newlist.head = nullptr;
	}


	void Invert()
	{
		Node* prev = nullptr;
		Node* current = head;
		Node* next = nullptr;

		while (current != nullptr)
		{
			next = current->next;

			current->next = prev;

			prev = current;
			current = next;
		}

		head = prev;
	}

};

class queuewithlinklist
{
public:
	LinkedList queue;

	void inqueue(int value)
	{
		queue.InsertAtFirst(value);
	}


	int dequeue()
	{
		return queue.RemoveNodeAtEnd();
	}


	int peek()
	{
		if (!queue.head)
		{
			cout << "there is nothing to peek\n";
			return -1;
		}
		int x = queue.RemoveNodeAtBegin();
		queue.InsertAtFirst(x);
		return x;
	}


	void reverse()
	{
		if (!queue.head)
		{
			cout << "there is nothing to peek\n";
			return;
		}
		queue.Invert();
	}


	void display()
	{
		queue.Display();
	}
};


class stackwithlinklist
{
public:
	LinkedList stack;

	void push(int value)
	{
		stack.InsertAtEnd(value);
	}


	int pop()
	{
		return stack.RemoveNodeAtEnd();
	}


	int peek()
	{
		if (!stack.head)
		{
			cout << "there is nothing to peek\n";
			return -1;
		}
		int x = stack.RemoveNodeAtEnd();
		stack.InsertAtEnd(x);
		return x;
	}


	void reverse()
	{
		if (!stack.head)
		{
			cout << "there is nothing to peek\n";
			return;
		}
		stack.Invert();
	}


	void display()
	{
		stack.Display();
	}
};


class arraywithlinklist
{
public:
	LinkedList array;

	arraywithlinklist(int size)
	{
		int i = 0;
		while (i < size)
		{
			int x = rand();
			array.InsertAtIndex(x,i);
			i++;
		}
	}


	void insert(int value, int index)
	{
		array.InsertAtIndex(value, index);
	}


	void append(int value)
	{
		array.InsertAtEnd(value);
	}


	void display()
	{
		array.Display();
	}
};
int main()
{
	arraywithlinklist a(5);
	a.insert(4, 5);
	a.display();

}

