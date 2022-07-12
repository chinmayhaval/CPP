#include<iostream>
#include<queue>
using namespace std;

int main()
{
    // Initialisation of queue using C++ STL
    queue<int> q;

    // Inserting elements in the queue
    q.push(10);
    q.push(20);
    q.push(30);

    // Printing the size of the queue
    cout<<"Size is: "<<q.size()<<endl;

    // Deleting an element and then printing the size of the queue
    q.pop();
    cout<<"Size is: "<<q.size()<<endl;

    // Checking if queue is empty
    // returns '1' for true and '0' for false
    if(q.empty())
        cout<<"Queue is empty."<<endl;
    else
        cout<<"Queue is not empty."<<endl;

    // Checking front and rear element
    cout<<"The front element is: "<<q.front()<<endl;
    cout<<"The rear element is: "<<q.back()<<endl;
    return 0;
}