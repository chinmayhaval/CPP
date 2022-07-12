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
};

void getNode(node* &head, node* &tail, int n)
{
    int d;

    for(int i=0;i<n;i++)
    {
        cout<<"Enter the element in the list "<<i+1<<": ";
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

int get_length(node* &head)
{
    int count = 0;
    node* temp = head;
    while(temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

int middle_element(node* &head)
{
    int len = get_length(head);
    int mid = len/2;
    node* temp = head;
    int count = 0;

    while(count < mid)
    {
        temp = temp->next;
        count++;
    }
    return temp->data;
}

int main()
{
    int n;
    node* head = NULL;
    node* tail = NULL;

    cout<<"How many elements initially in Linked List?: ";
    cin>>n;

    getNode(head, tail, n);

    cout<<"The middle element is: "<<middle_element(head)<<endl;
    return 0;
}