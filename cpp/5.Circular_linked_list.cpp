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

void insert_beginning(node* &head, node* &tail, int data)
{
    node* newnode = new node(data);
    tail->next = newnode;
    newnode->next = head;
    head = newnode;
}

void insert_end(node* &head, node* &tail, int data)
{
    node* newnode = new node(data);
    tail->next = newnode;
    newnode->next = head;
    tail = newnode;
}

void insert_middle(node* &head, node* &tail, int pos, int data)
{
    node* temp = head;
    int count = 1;

    if(pos == 1)
    {
        insert_beginning(head, tail, data);
        return;
    }

    while(count++<pos-1)
    {
        temp = temp->next;
    }

    if(temp->next == NULL)
    {
        insert_end(head, tail, data);
        return;
    }

    node *newnode = new node(data);
    newnode->next = temp->next;
    temp->next = newnode;
    temp = NULL;
    delete temp;
}

void delete_beginning(node* &head, node* &tail)
{
    node* temp = head;
    tail->next = head->next;
    head = head->next;
    temp->next = NULL;
    delete temp;
}

void delete_end(node* &head, node* &tail)
{
    node* temp = head;

    while(temp->next != tail)
    {
        temp = temp->next;
    }
    temp->next = head;
    tail->next = NULL;
    node* supp = tail;
    tail = temp;
    temp = NULL;
    delete temp;
    delete supp;
}

void delete_middle(node *&head, node* &tail, int pos)
{
    node* temp = head;
    int count = 1;
    if (pos == 1)
    {
        delete_beginning(head, tail);
    }

    while(count++<pos-1)
    {
        temp = temp->next;
    }

    if(temp->next == head)
    {
        delete_end(head, tail);
    }

    node* supp = temp;
    temp = temp->next;
    supp->next = temp->next;
    supp = NULL;
    temp->next = NULL;
    delete temp;
    delete supp;
    
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
    traverse(head);

    insert_beginning(head, tail, 0);
    traverse(head);

    insert_end(head, tail, 100);
    traverse(head);

    insert_middle(head, tail, 4, 300);
    traverse(head);

    delete_beginning(head, tail);
    traverse(head);

    delete_end(head, tail);
    traverse(head);

    delete_middle(head, tail, 4);
    traverse(head);
    
    return 0;
}