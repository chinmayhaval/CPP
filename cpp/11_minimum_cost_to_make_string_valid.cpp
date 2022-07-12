/*  You are given a string 'STR' containing either '{' or '}'. 'STR' is called valid if all the brackets are
    balanced. Formally for each opening bracket, there must be a closing bracket right to it.

    You want to make 'STR' valid by performing some operations on it. In one operation, he can convert
    '{' into '}' or vice-versa and the cost of such operation is 1.

    Your task is to determine minimum cost to make 'STR' valid.     */

#include<iostream>
#include<stack>
using namespace std;

int findMinimumCost(string str)
{
    if(str.length()%2 != 0)
    {
        return -1;
    }

    stack<char> s;

    for(int i=0;i<str.length();i++)
    {
        char ch = str[i];

        if(ch == '(')
        {
            s.push(ch);
        }
        else
        {
            if(!s.empty() && s.top() == '(')
            {
                s.pop();
            }
            else
            {
                s.push(ch);
            }
        }
    }
    // Now stack contains invalid expression
    int a = 0, b = 0;

    while(!s.empty())
    {
        if(s.top() == '(')
        {
            a++;
        }
        else
        {
            b++;
        }
        s.pop();
    }

    int ans = (a+b)/2;
    return ans;
}

int main()
{
    string str = "}{";
    cout<<findMinimumCost(str)<<endl;
    return 0;
}