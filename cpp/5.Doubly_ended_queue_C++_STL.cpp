/*  Doubly ended queue: A type of 'Queue data structure' that allows both insertion and deletion from both ends. */

#include<iostream>
#include<queue>
using namespace std;

int main()
{
    // Creating a deque using C++ STL
    deque<int> d;

    // Inserting the element from the front
    d.push_front(10);
    d.push_front(5);

    // Inserting the element from the end
    d.push_back(15);
    d.push_back(20);

    // Printing the front and end element
    cout<<d.front()<<endl;
    cout<<d.back()<<endl;

    // Printing the size
    cout<<d.size()<<endl;

    // Deleting the element from the front
    d.pop_front();

    // Deleting the element from the end
    d.pop_back();

    // Printing the front and end element
    cout<<d.front()<<endl;
    cout<<d.back()<<endl;

    // Printing the size
    cout<<d.size()<<endl;

    // Checking whether the queue is empty or not
    if(d.empty())
        cout<<"The deque is empty."<<endl;
    else
        cout<<"The deque is not empty."<<endl;
    return 0;
}