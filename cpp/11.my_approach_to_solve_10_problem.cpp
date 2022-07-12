
#include<iostream>
using namespace std;

class node
{
    public:

    int data;
    node* next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void getNode(node* &head, node* &tail, int n)
{
    int d;

    for(int i=0;i<n;i++)
    {
        cout<<"Enter the element in the list "<<i+1<<": ";
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

int middle_element(node* &head)
{
    if(head == NULL)
    {
        cout<<"The List is empty."<<endl;
        return -1;
    }
    if(head->next == NULL)
    {
        return head->data;
    }
    if(head->next->next == NULL)
    {
        return head->next->data;
    }

    node* fast = head;
    node* slow = head;

    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->data;
}

int main()
{
    int n;
    node* head = NULL;
    node* tail = NULL;

    cout<<"How many elements initially in Linked List?: ";
    cin>>n;

    getNode(head, tail, n);

    cout<<"The middle element is: "<<middle_element(head)<<endl;
    return 0;
}