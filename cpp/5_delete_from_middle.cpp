/*  You are having a stack of size 'N+1', your task is to delete the middle most element so that the
    size of the resulting stack is 'N'.     */

#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int> &s, int count, int size)
{
    // base case
    if (count == (size / 2))
    {
        cout << "The top element " << s.top() << " has been deleted.\n";
        s.pop();
        return;
    }
    int num = s.top();
    s.pop();

    // recursive call
    solve(s, count + 1, size);
    s.push(num);
}

int main()
{
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    int n = s.size();
    solve(s, 0, n);

    return 0;
}