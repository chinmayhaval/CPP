#include<iostream>
using namespace std;

class queue
{
    int *arr;
    int qfront;
    int qrear;
    int size;

    public:
    // constructor
    queue(int size)
    {
        this->size = size;
        arr = new int[size];
        qfront = 0;
        qrear = 0;
    }

    bool isEmpty()
    {
        if(qfront == qrear)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if(qrear == size)
            return true;
        else
            return false;
    }

    void push(int data)
    {
        if(isFull())
        {
            cout<<"Queue is Full."<<endl;
            return;
        }
        else
        {
            arr[qrear] = data;
            qrear++;
        }
    }

    void pop()
    {
        if(isEmpty())
        {
            cout<<"Queue is empty."<<endl;
            return;
        }
        else
        {
            arr[qfront] = -1;
            qfront++;
            if(qfront == qrear)
            {
                qfront = qrear = 0;
            }
        }
    }

    int front()
    {
        if(isEmpty())
            return -1;
        else
            return arr[qfront];
    }

    int rear()
    {
        if(isEmpty())
            return -1;
        else
            return arr[qrear-1];
    }

};

int main()
{
    // Creating queue
    queue q(5);

    // Pushing the elements
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    // Deleting an element
    q.pop();

    // Checking front and rear element
    cout<<"Front(): "<<q.front()<<endl;
    cout<<"Rear(): "<<q.rear()<<endl;

    // Checking whether queue is empty
    cout<<"isEmpty(): "<<q.isEmpty()<<endl;

    // Checking whether queue is full
    cout<<"isFull(): "<<q.isFull()<<endl;
    return 0;
}