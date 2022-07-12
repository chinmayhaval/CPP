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

void removeDuplicates(node* head)
{

    if(head == NULL)
    {
        return;
    }
    node* curr = head;
    while(curr->next != NULL)
    {
        if(curr->data == curr->next->data)
        {
            node* deleteNode = curr->next;
            curr->next = curr->next->next;
            delete deleteNode;
        }
        else
        {
            curr = curr->next;
        }
    }
}

int main()
{
    node* head = NULL;
    node* tail = NULL;

    int n;

    cout<<"The number of nodes you want initially: ";
    cin>>n;

    getnode(head, tail, n);

    cout<<"\nBefore removing duplicates from the Linked List\n";
    traverse(head);

    removeDuplicates(head);

    cout<<"\nAfter removing duplicates from the Linked List\n";
    traverse(head);
    return 0;
}