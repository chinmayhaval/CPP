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

    ~node()
    {
        int value = this->data;
        if(this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout<<"Node deleted with the value "<<value<<endl;
    }
};

void getnode(node* &head, node* &tail, int data)
{
    node* newnode = new node(data);

    if(head == NULL)
    {
        head = tail = newnode;
    }
    else
    {
        tail->next = newnode;
        tail = newnode;
        tail->next = head;
    }
}

void traverse(node* &head)
{
    node* temp = head;
    cout<<temp->data<<" ";
    temp = temp->next;
    while(temp != head)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int length(node* head)
{
    node* temp = head->next;
    int count = 1;

    while(temp != head)
    {
        count++;
        temp = temp->next;
    }
    if(count%2 == 0)
        return count-1;
    else
        return count;
}

void DividingCircularLinkedList(node* head)
{
    int len = length(head);
    int mid = len/2;
    int counter = 0;

    node* head2 = head;

    while(counter++ < mid)
    {
        head2 = head2->next;
    }

    node* temp = head2;
    head2 = head2->next;
    temp->next = head;

    temp = head2;
    while(temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = head2;

    // First Circular Linked List
    node* temp2 = head;
    cout<<"The first Circular Linked List\n";
    cout<<temp2->data<<" ";
    temp2 = temp2->next;
    while(temp2 != head)
    {
        cout<<temp2->data<<" ";
        temp2 = temp2->next;
    }
    cout<<endl;

    // Second Circular Linked List
    temp2 = head2;
    cout<<"The second Circular Linked List\n";
    cout<<temp2->data<<" ";
    temp2 = temp2->next;
    while(temp2 != head2)
    {
        cout<<temp2->data<<" ";
        temp2 = temp2->next;
    }
    cout<<endl;
}

int main()
{
    node* head = NULL;
    node* tail = NULL;

    getnode(head, tail, 10);
    getnode(head, tail, 20);
    getnode(head, tail, 30);
    getnode(head, tail, 40);
    getnode(head, tail, 50);
    getnode(head, tail, 60);
    getnode(head, tail, 70);
    getnode(head, tail, 80);
    traverse(head);

    DividingCircularLinkedList(head);

    return 0;
}