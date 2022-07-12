/*  Given a valid mathematical expression in the form of a string. You are supposed to return true if the
    given expression contains a pair of redundant brackets, else return false. The given string only contains
    '(',')','+','-','*','/' and lowercase english letters.

    Note: A pair of brackets is said to be redundant when a subexpression is surrounded by needless/unless
    brackets.       */


#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool findRedundantBrackets(string &str)
{
    stack <char> s;
    for(int i=0;i<str.length();i++)
    {
        char ch = str[i];

        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            s.push(ch);
        }
        else
        {
            if(ch == ')')
            {
                bool isRedundant = true;
                while(s.top() != '(')
                {
                    char top = s.top();
                    if(top == '+' || top == '-' || top == '*' || top == '/')
                    {
                        isRedundant = false;
                        s.pop();
                    }
                }
                if(isRedundant == true)
                    return true;
                s.pop();
            }
        }
        
    }
    return false;
}

int main()
{
    string str = "((a+b))";

    cout<<findRedundantBrackets(str)<<endl;
    return 0;
}