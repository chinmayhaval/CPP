/*  You are given a string consisting solely of "{","}" , "(",")" , "[" , "]".
    Determine whether the parentheses are balanced.                 */

#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool solve(string &str)
{
    stack<char> s;
    char ch, top;

    for(int i=0 ; i<str.length() ; i++)
    {
        ch = str[i];
        
        // if parentheses is opening bracket
        if(ch == '(' || '{' || '[')
        {
            s.push(ch);
        }
        else// if(ch == ')' || '}' || ']')
        {
            if(!s.empty())
            {
                top = s.top();
                if((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '['))
                {
                    s.pop();
                    // if(s.empty())
                    // {
                    //     return true;
                    // }
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;

            }
        }
    }
    return true;
}

int main()
{
    string str;

    cout<<"Enter the string containing parentheses\n";
    getline(cin, str);

    if(solve(str))
    {
        cout<<"Balanced\n";
    }
    else
    {
        cout<<"Not Balanced\n";
    }

    return 0;
}