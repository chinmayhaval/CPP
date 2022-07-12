/*  You are given a stack of integers 'MyStack' and an integer 'X'. Your task is to insert 'x' at the bottom
    of 'MyStack' and return the updated stack.   */

#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int> &s, int x)
{
    // base condition
    if(s.empty())
    {
        s.push(x);
        return;
    }

    int number = s.top();
    s.pop();
    // recursive call
    solve(s, x);
    s.push(number);
}

int main()
{
    stack<int> s;
    int n,num;

    cout<<"\nEnter the number of elements you want to insert in stack: ";
    cin>>n;

    cout<<"\nEnter the elements in the stack\n";
    for(int i=0;i<n;i++)
    {
        cin>>num;
        s.push(num);
    }

    int x;
    cout<<"\nEnter the element you want to insert at the bottom of the stack: ";
    cin>>x;

    solve(s, x);

    cout<<"\nThe new stack is\n";
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl<<endl;
    return 0;
}