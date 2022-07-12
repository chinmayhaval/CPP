/*  Design a data structure, which represents two stacks using only one array common for both stacks.
    The data structure should support the following operations:

    push1(NUM) - Push 'NUM' in stack 1.
    push2(NUM) - Push 'NUM' in stack 2.
         pop1() - Pop out a top element from stack 1 and return popped element, in case of underflow return -1.
         pop2() - Pop out a top element from stack 2 and return popped element, in case of underflow return -1. */

#include <iostream>
using namespace std;

class twoStacks
{
    int top1;
    int top2;
    int *arr;
    int size;

public:
    // constructor
    twoStacks(int size)
    {
        this->size = size;
        top1 = -1;
        top2 = size;
        arr = new int[size];
    }

    // operations
    void push1(int data)
    {
        // there should at least a space available to insert an element
        if (top2 > top1 + 1)
        {
            top1++;
            arr[top1] = data;
        }
        else
        {
            cout << "Stack Overflow!!!\n";
        }
    }

    void push2(int data)
    {
        // there would also be same condition
        if (top2 > top1 + 1)
        {
            top2--;
            arr[top2] = data;
        }
        else
        {
            cout << "Stack Overflow!!!\n";
        }
    }

    int pop1()
    {
        if (top1 == -1)
        {
            return -1;
        }
        else
        {
            int ans = arr[top1];
            top1--;
            return ans;
        }
    }

    int pop2()
    {
        if (top2 == size - 1)
        {
            return -1;
        }
        else
        {
            int ans = arr[top2];
            top2++;
            return ans;
        }
    }
};

int main()
{
    twoStacks s(10);

    s.push1(10);
    s.push1(20);
    s.push1(30);
    s.push1(40);
    s.push1(50);
    s.push1(60);
    s.push2(70);
    s.push2(80);
    s.push2(90);
    s.push2(100);

    cout << s.pop1() << endl;
    cout << s.pop2() << endl;
    cout << s.pop1() << endl;
    cout << s.pop2() << endl;
    return 0;
}
