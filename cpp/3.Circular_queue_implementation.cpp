#include<iostream>
using namespace std;

class circularQueue
{
    int *arr;
    int size;
    int qfront;
    int qrear;

    public:

    // constructor
    circularQueue(int size)
    {
        this->size = size;
        arr = new int[size];
        qfront = qrear = -1;
    }

    void push(int data)
    {
        if((qfront == 0 && qrear == size-1) || (qrear == (qfront - 1)%(size-1)))
        {
            cout<<"Stack is full!!!"<<endl;
            return;
        }
        else if(qrear == -1)
        {
            qfront = qrear = 0;
            arr[qrear] = data;
        }
        else if((qrear == size-1) && (qfront != 0))
        {
            qrear = 0;          // To maintain cyclic nature
            arr[qrear] = data;
        }
        else
        {
            qrear++;
            arr[qrear] = data;
        }
    }

    void pop()
    {
        if(qfront == -1)
        {
            cout<<"Queue is empty!!!"<<endl;
            return;
        }

        cout<<arr[qfront]<<" has been popped."<<endl;
        arr[qfront] = -1;

        if(qfront == qrear)
        {
            qfront = qrear = -1;
        }
        else if(qfront == size - 1)
        {
            qfront = 0;  // To maintain cyclic nature
        }
        else
        {
            qfront++;
        }
    }
};

int main()
{
    // Initialization of circular queue
    circularQueue q(5);

    // Inserting the elements in the circular queue
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    // Deleting the elements from the circular queue
    q.pop();
    q.pop();
    return 0;
}