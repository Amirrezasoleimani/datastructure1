#include <iostream>
using namespace std;

class CircularQueue {
private:
    int size;
    int rear;
    int front;
    int* queue = new int[size];;

public:
    CircularQueue(int s)
    {
        size = s;
        rear = -1;
        front = -1;
    }

    bool isEmpty() 
    {
        return (front == -1);
    }

    bool isFull()
    {
        return (rear + 1) % size == front;
    }

    void enqueue(int value)
    {
        if (isFull()) 
        {
            cout << "Queue is full"<< endl;
            return;
        }
        if (isEmpty())
        {
            front = 0;
        }
        rear = (rear + 1) % size;
        queue[rear] = value;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        int deletedItem = queue[front];
        cout << "Deleted item is  " << deletedItem << endl;
        if (front == rear)
        {
            front = rear = -1;
        }
        else 
        {
            front = (front + 1) % size;
        }
    }

    int peek() 
    {
        if (isEmpty())
        {
            cout << "Queue is empty, nothing to peek" << endl;
            return -1;
        }
        return queue[front];
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "{";
        int i = front;
        while (true) 
        {
            cout << queue[i];
            if (i == rear) break;
            cout << ", ";
            i = (i + 1) % size;
        }
        cout << "}" << endl;
    }
};

int main() {
    CircularQueue cq(5);
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.display();
    cout << "Peek: " << cq.peek() << endl;
    cq.dequeue();
    cq.display();
    cq.enqueue(40);
    cq.enqueue(50);
    cq.enqueue(60);
    cq.display();
    cq.dequeue();
    cq.enqueue(60);
    cq.display();

}

