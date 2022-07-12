/*  Given a singly linked list, you have to detect the loop and remove the loop from the linked list, 
    if present. You have to make changes in the given Linked List itself and return the updated Linked List.  */


/*  T.C. -> O(n)
    S.C. -> O(n)            */

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

bool detectLoop(node* head)
{
    if(head == NULL)
    {
        // not even a single node is present.
        return false;
    }
    map<node* , bool> visited;
    node* temp = head;

    while(temp!=NULL)
    {
        if(visited[temp] == true)
        {
            // we found a cycle in Linked List
            cout<<"Cycle has been started from "<<temp->data<<endl;
            return true;
        }
        else
        {
            visited[temp] = true;
            temp = temp->next;
        }
    }
    return false;
}

int main()
{
    int n;
    node* head = NULL;
    node* tail = NULL;

    cout<<"Enter n: ";
    cin>>n;

    getnode(head, tail, n);

    tail->next = head->next->next;

    if(detectLoop(head))
    {
        cout<<"Present\n";
    }
    else
    {
        cout<<"Not present\n";
    }

    return 0;
}