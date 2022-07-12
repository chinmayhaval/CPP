#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<char> s;
    string ch;

    cout << "Enter a string: ";
    getline(cin, ch);

    for (int i = 0; i < ch.length(); i++)
    {
        s.push(ch[i]);
    }

    cout << "\nReverse string is\n";
    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }
    cout << endl;
    return 0;
}