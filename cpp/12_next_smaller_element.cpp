/*  You are given an array of integers of particular size. Your task is to find the next smaller element for
    each of the array elements.
    If for an array element the next smaller element doesn't exist, you should print -1 for that array
    element.        */

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void nextSmallerElement(vector<int> &arr, int n, vector<int> &ans)
{
    stack<int> s;
    s.push(-1);

    for(int i=n-1;i>=0;i--)
    {
        while(s.top() >= arr[i])
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(arr[i]);
    }
}

int main()
{
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;

    vector<int> arr(n);
    vector<int> ans(n);

    cout<<"Enter the elements in the vector\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        ans[i] = 0;
    }

    nextSmallerElement(arr, n, ans);

    for(int i=0;i<n;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}