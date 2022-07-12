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

void kreverse(node* &head, int k)
{
    // base case
    if(head == NULL)
    {
        return;
    }

    // step1: reverse first k nodes
    node* next = NULL;
    node* curr = head;
    node* prev = NULL;
    int count=0;

    while(curr != NULL && count++ < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // step2: recursion call
    if(curr != NULL)
    {
        int count=0;
        node* temp = curr;
        while(count++ < k-1)
        {
            if(temp->next != NULL)
            {
                temp = temp->next;
            }
        }
        head->next = temp; 
        kreverse(curr, k);
    }

    head = prev;
}

int main()
{
    node* head;
    node* tail;
    head = tail = NULL;
    int n, k;

    cout<<"Enter the number of nodes you want to create initially: ";
    cin>>n;

    cout<<"Enter the k value: ";
    cin>>k;

    getnode(head, tail, n);

    cout<<"The Linked List before reversing in "<<k<<" group\n";
    traverse(head);

    kreverse(head, k);

    cout<<"The Linked List after reversing in "<<k<<" group\n";
    traverse(head);
    return 0;
}