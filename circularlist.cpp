#include <iostream>
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

class CircularLinkedList
{
public:
    Node* head;

    CircularLinkedList()
    {
        head = nullptr;
    }

    void Display()
    {
        if (!head) {
            std::cout << "List is empty" << std::endl;
            return;
        }
        Node* temp = head;
        do
        {
            cout << temp->data << "->";
            temp = temp->next;
        } while (temp != head);
        cout << "head" << endl;

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
            if (!head)
            {
                head = item;
                head->next = head;
            }
            else
            {
                item->next = head;
                Node* temp = head;
                while (temp->next != head)
                {
                    temp = temp->next;
                }
                temp->next = item;
                head = item;
            }

            return;
        }

        Node* temp = head;
        int i = 0;
        if (temp)
        {
            for (i = 0; i < index - 1 && temp->next != head; i++)
            {
                temp = temp->next;
            }
        }

        if (!temp || temp->next == head)
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
            head->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = item;
        item->next = head;
    }


    void InsertAtFirst(int data)
    {
        Node* item = new Node(data);
        if (!head) {
            head = item;
            head->next = head;
            return;
        }
        item->next = head;
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = item;
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
        int i = 0;
        if (temp) {
            for (i = 0; i < index && temp->next != head; ++i)
            {
                temp = temp->next;
            }
        }

        if (!temp || (i != index && temp->next == head))
        {
            cout << "Index does not exist\n";
            return;
        }

        temp->data = data;
    }


    int RemoveNodeAtIndex(int index)
    {
        if (!head)
        {
            cout << "List is empty\n";
            return -1;
        }

        if (index < 0)
        {
            cout << "index is not correct\n";
            return -1;
        }
        Node* temp = head;
        if (index == 0)
        {
            int x = head->data;
            if (head->next == head)
            {
                head = nullptr;
                return x;
            }
            Node* last = head;
            while (last->next != head) 
            {
                last = last->next;
            }
            head = head->next;
            last->next = head;
            return x;
        }

        int i = 0;
        if (temp) 
        {
            for (i = 0; i < index - 1 && temp->next != head; ++i)
            {
                temp = temp->next;
            }
        }
        if (temp == nullptr || temp->next == head)
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
        int x = head->data;
        if (head->next == head)
        {
            head = nullptr;
            return x;
        }
        Node* last = head;
        while (last->next != head)
        {
            last = last->next;
        }
        head = head->next;
        last->next = head;
        return x;
    }


    int RemoveNodeAtEnd()
    {
        if (!head)
        {
            cout << "List is empty." << endl;
            return -1;
        }

        if (head->next == head)
        {
            int x = head->data;
            head = nullptr;
            return x;
        }

        Node* temp = head;
        while (temp->next->next != head)
        {
            temp = temp->next;
        }
        int x = temp->next->data;
        temp->next = head;
        return x;
    }


    int SizeOfList()
    {
        if (!head) 
        {
            return 0;
        }
        int count = 0;
        Node* temp = head;
        do
        {
            temp = temp->next;
            count++;
        } while (temp != head);
        return count;
    }

    void Concatenate(CircularLinkedList newlist)
    {
        if (!newlist.head)
        {
            cout << "newlist is empty\n";
            return;
        }

        if (!head)
        {
            head = newlist.head;
            Node* temp = head;
            while (temp->next != newlist.head) 
            {
                temp = temp->next;
            }
            temp->next = head;
            newlist.head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        Node* temp2 = newlist.head;
        while (temp2->next != newlist.head) {
            temp2 = temp2->next;
        }
        temp->next = newlist.head;
        temp2->next = head;
        newlist.head = nullptr;
    }

    void Invert()
    {
        if (!head || head->next == head) 
        {
            return;
        }
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        Node* last = head;
        while (last->next != head)
        {
            last = last->next;
        }

        do
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        } while (current != head);
        head->next = prev;
        last->next = prev;
        head = prev;
    }

};
int main() 
{
    CircularLinkedList list1;
    list1.InsertAtEnd(1);
    list1.InsertAtEnd(2);
    list1.InsertAtEnd(3);
    list1.InsertAtEnd(4);
    list1.Display();

    list1.Invert();
    list1.Display();

    CircularLinkedList list2;
    list2.InsertAtEnd(5);
    list2.InsertAtEnd(6);
    list2.Display();

    list1.Concatenate(list2);
    list1.Display();

    cout << list1.RemoveNodeAtEnd() << endl;
    list1.Display();

    cout << list1.RemoveNodeAtIndex(2) << endl;
    list1.Display();

    list1.InsertAtIndex(7, 2);
    list1.Display();

    list1.UpdateNode(8, 3);
    list1.Display();

    cout << "size of list is: " << list1.SizeOfList() << endl;

    return 0;
}

