#include<iostream>
using namespace std;

class deque
{
    int qfront;
    int qrear;
    int *arr;
    int size;

    public:
    // Constructor
    deque(int size)
    {
        this->size = size;
        arr = new int[size];
        qrear = -1;
        qfront = -1;
    }

    void pushFront(int data)
    {
        // Check whether full or not
        if(isFull())
        {
            cout<<"Queue is full."<<endl;
            return;
        }
        else if(isEmpty())
        {
            qfront = qrear = 0;
        }
        else if((qfront == 0) && (qrear != size-1))
        {
            qfront = size-1;
        }
        else
        {
            qfront--;
        }
        arr[qfront] = data;
    }

    void pushBack(int data)
    {
        if(isFull())
        {
            cout<<"Queue is full."<<endl;
            return;
        }
        else if(isEmpty())
        {
            qfront = qrear = 0;
        }
        else if((qrear == size-1) && (qfront != 0))
        {
            qrear = 0;
        }
        else
        {
            qrear++;
        }
        arr[qrear] = data;
    }

    void popFront()
    {
        if(qfront == -1)
        {
            cout<<"Queue is empty."<<endl;
            return;
        }
        
        cout<<arr[qfront]<<" has been popped."<<endl;
        arr[qfront] = -1;

        if(qfront == qrear)
        {
            qfront = qrear = -1;
        }
        else if(qfront == size-1)
        {
            qfront = 0;
        }
        else
        {
            qfront++;
        }
    }

    void popBack()
    {
        if(qfront == -1)
        {
            cout<<"Queue is empty."<<endl;
            return;
        }

        cout<<arr[qrear]<<" has been popped."<<endl;
        arr[qrear] = -1;

        if(qfront == qrear)
        {
            qfront = qrear = -1;
        }
        else if(qrear == 0)
        {
            qrear = size-1;
        }
        else
        {
            qrear--;
        }
    }

    bool isEmpty()
    {
        if(qfront == -1)
            return true;
        else
            return false;
    }

    int getFront()
    {
        if(isEmpty())
            return -1;
        else
            return arr[qfront];
    }

    int getBack()
    {
        if(isEmpty())
            return -1;
        else
            return arr[qrear];
    }

    bool isFull()
    {
        if((qfront == 0 && qrear == size-1) || ((qfront !=0) && (qrear == qfront-1)%(size-1)))
            return true;
        else
            return false;
    }
};

int main()
{
    deque d(5);
    int ch, data;

    cout<<"Operations on deque\n1. Push Front\n2. Push Back\n3. Pop Front\n4. Pop Back\n5. Empty\n6. Full\n7. Get Front\n8. Get Back\n9. Exit\n";

    do
    {
        cout<<"Enter your choice: ";
        cin>>ch;

        switch(ch)
        {
            case 1:
            {
                cout<<"Enter the data: ";
                cin>>data;
                d.pushFront(data);
                cout<<endl;
                break;
            }
            case 2:
            {
                cout<<"Enter the data: ";
                cin>>data;
                d.pushBack(data);
                cout<<endl;
                break;
            }
            case 3:
            {
                d.popFront();
                break;
            }
            case 4:
            {
                d.popBack();
                break;
            }
            case 5:
            {
                if(d.isEmpty())
                    cout<<"Queue is empty."<<endl;
                else
                    cout<<"Queue is not empty."<<endl;
                break;
            }
            case 6:
            {
                if(d.isFull())
                    cout<<"Queue is full."<<endl;
                else
                    cout<<"Queue is not full."<<endl;
                break;
            }
            case 7:
            {
                cout<<d.getFront()<<endl;
                break;
            }
            case 8:
            {
                cout<<d.getBack()<<endl;
                break;
            }
            case 9:
            {

            }
        }
    } while (ch !=9);
    
    return 0;
}