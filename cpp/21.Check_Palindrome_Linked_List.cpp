/*  Approach1: Store Linked List elements in an array and then use algo. for array to check palindrome condition.   */
/******************  
    T.C. -> O(n)
    S.C -> O(n)
 ******************/

#include<iostream>
#include<vector>
using namespace std;

class node
{
    public:
    int data;
    node* next;

    // Constructor
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void getnode(node* &head, node* &tail, int n)
{
    int d;
    
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the data in the node "<<i+1<<": ";
        cin>>d;
        node* newnode = new node(d);

        if(head == NULL)
        {
            head = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
    }
}

void traverse(node* &head)
{
    node* temp = head;

    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

bool checkPalindrome(vector<int> arr)
{
    int n = arr.size();
    int s = 0;
    int e = n-1;

    while(s<=e)
    {
        if(arr[s++] != arr[e--])
        {
            return 0;
        }
    }
    return 1;

}

bool isPalindrome(node* head)
{
    vector<int> arr;
    node* temp = head;
    while(temp != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }
    return checkPalindrome(arr);
}

int main()
{
    int n;
    node* head = NULL;
    node* tail = NULL;

    cout<<"How many elements initially is list: ";
    cin>>n;

    getnode(head, tail, n);

    bool ans = isPalindrome(head);

    if(ans)
        cout<<"The List is a Palondrome."<<endl;
    else
        cout<<"The List is not a Palondrome."<<endl;
    return 0;
}
