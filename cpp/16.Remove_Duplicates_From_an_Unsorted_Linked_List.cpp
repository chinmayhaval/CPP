#include<iostream>
#include<map>
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

void removeDuplicate(node* head)
{
    if(head == NULL)
    {
        return;
    }

    map<int,bool> visited;  // By default, bool value is 'false'.
    node* curr = head;
    node* prev = NULL;

    while(curr != NULL)
    {
        if(visited[curr->data] == true)
        {
            node* toDelete = curr;
            prev->next = curr->next;
            curr = curr->next;
            toDelete->next = NULL;
            delete toDelete;
        }
        else
        {
            visited[curr->data] = true;
            prev = curr;
            curr = curr->next;
        }
    }
}

int main()
{
    node* head = NULL;
    node* tail = NULL;

    int n;
    cout<<"Enter the number of nodes: ";
    cin>>n;

    getnode(head, tail, n);

    cout<<"\nLinked List before removing duplicate elements\n";
    traverse(head);

    removeDuplicate(head);

    cout<<"\nLinked List after removing duplicate elements\n";
    traverse(head);

    return 0;
}