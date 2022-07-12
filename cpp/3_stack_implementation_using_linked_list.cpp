#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    // Constructor
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // Destructor
    ~node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "The popped element is " << value << endl;
    }
};

void push(node *&head, int data)
{
    node *newnode = new node(data);
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
}

void pop(node *&head)
{
    if (head == NULL)
    {
        cout << "Stack Underflow!!!\n";
    }
    else
    {
        node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
}

void peek(node *&head)
{
    if (head == NULL)
    {
        cout << "Stack is empty.\n";
    }
    else
    {
        cout << head->data << endl;
    }
}

int main()
{
    node *head = NULL;

    push(head, 10);
    push(head, 20);
    push(head, 30);
    push(head, 40);
    pop(head);
    pop(head);
    peek(head);
    return 0;
}