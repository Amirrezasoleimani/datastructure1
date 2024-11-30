#include <iostream>
using namespace std;

//this program is Quque implement
class Quque
{
private:
    int size;
    int rear;
    int front;
    int* quque = new int[size];

public:
    Quque(int s)
    {
        size = s;
        rear = -1;
        front = -1;
    }

    bool isempty()
    {
        return front == rear;
    }

    bool isfull()
    {
        return rear == size - 1;
    }
    void shift()
    {
        int t = front;
        for (int i = 0; i <= front; i++)
        {
            for (int j = 0; j < (rear - front); j++)
            {
                quque[t] = quque[t + 1];
                t = t + 1;
            }
            front = front - 1;
            rear = rear - 1;
        }
    }

    void enquque(int value)
    {
        if (isfull())
        {
            if (front == -1 && rear == size - 1)
            {
                cout << "quque is full" << endl;
            }
            if (front > -1 && rear == size - 1)
            {
                shift();
                rear = rear + 1;
                quque[rear] = value;
            }
        }
        else
        {
            rear += 1;
            quque[rear] = value;
        }
    }

    void deletequque()
    {
        if (isempty())
        {
            cout << "quque is empty" << endl;
        }
        else
        {
            front ++;
            int temple = quque[front];
            cout << "deleted item is = " << temple << endl;
        }
    }
    void display()
    {
        cout << "your last quque update" << endl;
        cout << "{";
        for (int i = front + 1; i <= rear; i++)
        {
            cout << quque[i];
            if (i < rear)
            {
                cout << ",";
            }
        }
        cout << "}" << endl;
    }
};

int main()
{
    Quque exam(7);
    exam.enquque(2);
    exam.enquque(3);
    exam.display();
    exam.deletequque();
    exam.display();
}