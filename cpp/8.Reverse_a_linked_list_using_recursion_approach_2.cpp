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

node* reverse_linked_list(node* &head)
{
    // base condition
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    // recursive call
    node* chotaHead = reverse_linked_list(head->next);
    head->next->next = head;
    head->next = NULL;
    return chotaHead;
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

    node* ans = reverse_linked_list(head);

    cout<<"The Linked List after reversing\n";
    traverse(ans);
    return 0;
}