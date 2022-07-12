#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;

    // We are using the constructor to initialize the value in the node we create
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

void reverse_linked_list(node* &head)
{
    if(head == NULL)
    {
        cout<<"The list is empty"<<endl;
        return;
    }
    if(head->next == NULL)
    {
        cout<<"The list has only one element."<<endl;
        return;
    }

    node* prev = NULL;
    node* curr = head;
    node* forward = NULL;

    while(curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
}

int main()
{
    node* head;
    node* tail;
    head = tail = NULL;
    int n;

    cout<<"Enter the number of nodes you want to create initially: ";
    cin>>n;

    getnode(head, tail, n);

    cout<<"The Linked List before reversing\n";
    traverse(head);

    reverse_linked_list(head);

    cout<<"The Linked List after reversing\n";
    traverse(head);
    return 0;
}