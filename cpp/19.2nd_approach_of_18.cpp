/*  We don't want to replace or rewrite the data.
    In this case, we will be changing the links.    */

/*********************************  
    Time complexity -> O(nx)
    Space complexity -> O(1)
 *********************************/

#include<iostream>
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

void sortLinkedList(node* &head)
{
    if(head == NULL)
    {
        cout<<"The Linked List is empty.\n";
        return;
    }
    node* curr = head;
    node* prev = NULL;
    node* prev2 = NULL;

    while(curr->next != NULL)
    {
        if((curr == head) && (curr->data > curr->next->data))
        {
            node* temp = curr->next->next;
            curr->next->next = curr;
            head = curr->next;
            curr->next = temp;
            prev = head;
        }

        else if((curr->data > curr->next->data) && (head->data >= curr->next->data))
        {
            node* temp = head;
            head = curr->next;
            curr->next = head->next;
            head->next = temp;
        }

        else if((curr->data > curr->next->data) && (curr != head))
        {
            node* temp = curr->next->next;
            if(prev->data > curr->next->data)
            {
                prev2->next = curr->next;
                curr->next->next = prev;
                curr->next = temp;
                prev2 = prev2->next;
            }
            else
            {
                prev->next = curr->next;
                prev = curr->next;
                curr->next->next = curr;
                curr->next = temp;
            }
        }

        else if(curr->data <= curr->next->data)
        {
            prev2 = prev;
            prev = curr;
            curr = curr->next;
        }

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