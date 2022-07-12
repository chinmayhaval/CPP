/*  You are given a stack consisting of 'N' integers. Your task is to sort this stack in descending order
    using recursion.        */

#include<iostream>
#include<stack>
using namespace std;

void sortedStack(stack<int> &s, int num)
{
    // base case
    if(s.empty() || (!s.empty() && s.top() > num))
    {
        s.push(num);
        return;
    }

    int n = s.top();
    s.pop();
    // recursive call
    sortedStack(s, num);
    s.push(n);
}

void solve(stack<int> &s)
{
    // base case
    if(s.empty())
    {
        return;
    }

    int num = s.top();
    s.pop();

    // recursive call
    solve(s);
    
    sortedStack(s, num);
}

int main()
{
    stack<int> s;
    s.push(3);
    s.push(1);
    s.push(2);
    s.push(5);
    s.push(4);

    solve(s);

    cout<<"The sorted stack is\n";
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    return 0;
}