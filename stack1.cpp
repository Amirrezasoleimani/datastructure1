#include <iostream>
using namespace std;

class Stack
{
private:
    int size;
    int top;
    int* stack;

public:
    Stack(int size = 5)
    {
        this->size = size;
        this->top = -1;
        stack = new int[size];
    }

    bool fully_Empty()
    {
        return top == -1;
    }

    bool IsEmpty()
    {
        return top < size - 1;
    }

    void Push(int value)
    {
        if (IsEmpty())
        {
            stack[++top] = value;
        }
    }

    int Pop()
    {
        if (top >= 0)
        {
            int temple = stack[top--];
            return temple;
        }
        else
        {
            return -1;
        }
    }

    int Peek()
    {
        if (top >= 0)
        {
            return stack[top];
        }
        else
        {
            return -1;
        }
    }

    void Display()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << stack[i] << " ";
        }
        cout << "\n";
    }
};

class Queuewithstack
{
private:
    Stack stack1;
    Stack stack2;

public:
    Queuewithstack(int size = 5)
    {
        stack1 = size;
        stack2 = size;
    }

    void Transfer()
    {
        while(!(stack2.fully_Empty()))
        {
            stack1.Push(stack2.Pop());
        }
    }

    void Enqueue(int value)
    {
        if (stack1.IsEmpty())
        {
            stack1.Push(value);
        }
    }

    int Dequeue()
    {
        if (!(stack2.fully_Empty()))
        {
            Transfer();
        }
        while (!(stack1.fully_Empty()))
        {
            stack2.Push(stack1.Pop());
        }
        int x = stack2.Pop();
        return x;
    }

    void Displayq()
    {
        if (!(stack2.fully_Empty()))
        {
            Transfer();
        }

        while (!(stack1.fully_Empty()))
        {
            cout << stack1.Pop() << " ";
        }

    }
};
int main()
{
    Queuewithstack q;
    q.Enqueue(4);
    q.Enqueue(5);
    q.Displayq();
    
}
