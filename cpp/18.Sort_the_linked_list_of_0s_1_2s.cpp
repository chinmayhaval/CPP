/*  You are given a Linked List having N number of nodes and each node will have an integer which can be
    0, 1, or 2. You have to sort the iven Linked List in ascending order.   */

/********************************  
    Time complexity -> O(n)
    Space complexity -> O(1)
 ********************************/

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

void sortLinkedList(node* &head)
{
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    node* temp = head;
    while(temp != NULL)
    {
        if(temp->data == 0)
        {
            zeroCount++;
        }
        else if(temp->data == 1)
        {
            oneCount++;
        }
        else if(temp->data == 2)
        {
            twoCount++;
        }
        temp = temp->next;
    }
    temp = head;
    while(temp != NULL)
    {
        if(zeroCount != 0)
        {
            temp->data = 0;
            zeroCount--;
        }
        else if(oneCount != 0)
        {
            temp->data = 1;
            oneCount--;
        }
        else if(twoCount != 0)
        {
            temp->data = 2;
            twoCount--;
        }
        temp = temp->next;

    }
}

int main()
{
    int n;
    node* head = NULL;
    node* tail = NULL;

    cout<<"Enter the number of nodes you want initially: ";
    cin>>n;

    getnode(head, tail, n);

    cout<<"The Linked List before sorting\n";
    traverse(head);

    sortLinkedList(head);

    cout<<"The Linked List after sorting\n";
    traverse(head);
    return 0;
}