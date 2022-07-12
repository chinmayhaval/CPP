/*  Reverse a given stack of integers using recursion.  */
/*  Note: You are not allowed to use any extra space other than the internal stack space used due to recursion
    You are not allowed to use any loop constructs for any sort available as handy. for ex: for, while loop.
    The only stack inbuilt methods are allowed.     */

#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &s, int num)
{
    // base condition
    if (s.empty())
    {
        s.push(num);
        return;
    }

    int number = s.top();
    s.pop();
    // recursive call
    insertAtBottom(s, num);
    s.push(number);
}

void reverseStack(stack<int> &s)
{
    // base case
    if (s.empty())
    {
        return;
    }

    // recursive call
    int num = s.top();
    s.pop();

    reverseStack(s);
    insertAtBottom(s, num);
}

int main()
{
    stack<int> s;
    int n, element;

    cout << "\nFirst, enter some elements in the stack\n";
    cout << "The number of elements: ";
    cin >> n;

    cout << "\nEnter the elements\n";
    for (int i = 0; i < n; i++)
    {
        cin >> element;
        s.push(element);
    }

    reverseStack(s);

    cout << "\nThe reversed stack is\n";
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl
         << endl;
    return 0;
}