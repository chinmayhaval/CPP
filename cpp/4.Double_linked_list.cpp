#include<iostream>
using namespace std;

class node
{
    public:
    node* prev;
    int data;
    node* next;

    node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    ~node()
    {
        int val = data;
        
        if(this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout<<"Memory freed for node with data "<<val<<endl;
    }
};

void getnode(node* &head, node* &tail, int data)
{
    // int data;
    // cout<<"Enter the data in new node: ";
    // cin>>data;
    node* newnode = new node(data);

    if(head == NULL)
    {
        head = tail = newnode;
    }
    else
    {
        tail->next = newnode;
        newnode->prev = tail;
        tail = tail->next;
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

void insert_beginning(node* &head, int data)
{
    node* newnode = new node(data);
    head->prev = newnode;
    newnode->next = head;
    head = newnode;
}

void insert_end(node* &tail, int data)
{
    node* newnode = new node(data);
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}

void insert_middle(node* &head, node* &tail, int pos, int data)
{
    node* temp = head;

    int count = 1;

    if(pos == 1)
    {
        insert_beginning(head, data);
        return;
    }

    while(count++<pos-1)
    {
        temp = temp->next;
    }

    if(temp->next == NULL)
    {
        insert_end(tail, data);
        return;
    }

    node* newnode = new node(data);
    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next->prev = newnode;
    temp->next = newnode;
    temp = NULL;
    delete temp;
}

void delete_beginning(node* &head)
{
    node* temp = head;
    head->next->prev = NULL;
    head = head->next;
    temp->next = NULL;
    delete temp;
}

void delete_end(node* &tail)
{
    node* temp = tail;
    tail = tail->prev;
    temp->prev = NULL;
    tail->next = NULL;
    delete temp;
}

void delete_middle(node* &head, node* &tail, int pos)
{
    int count = 1;
    node* temp = head;

    if(pos == 1)
    {
        delete_beginning(head);
        return;
    }

    while(count++<pos)
    {
        temp = temp->next;
        if(temp->next == NULL)
        {
            delete_end(tail);
            return;
        }
    }
    
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    temp->prev = temp->next = NULL;
}

int main()
{
    node* head = NULL;
    node* tail = NULL;

    getnode(head, tail,30);
    getnode(head, tail,20);
    getnode(head, tail,15);
    getnode(head, tail,37);
    traverse(head);

    insert_beginning(head, 100);
    traverse(head);

    insert_end(tail, 231);
    traverse(head);

    insert_middle(head, tail, 3, 333);
    traverse(head);

    delete_beginning(head);
    traverse(head);

    delete_end(tail);
    traverse(head);

    delete_middle(head, tail, 1);
    traverse(head);
    
    return 0;
}