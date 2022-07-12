/*  Also known as Hare-Tortoise Algorithm is a pointer algorithm that uses only two pointers, moving through
    the sequence at different speeds. This algorithm is used to find a loop in a linked list. It uses two
    pointers one moving twice as fast as the other one. The faster one is called the faster pointer and the
    other one is called the slow pointer.
    T.C. -> O(n)
    S.C. -> O(1)    */

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

node* floydsDetectionLoop(node* head)
{
    if(head == NULL)
    {
        return NULL;
    }

    node* fast = head;
    node* slow = head;

    while(slow != NULL && fast != NULL)
    {
        fast = fast->next;
        if(fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;

        if(slow == fast)
        {
            return slow;
        }
    }
    return NULL;
}

node* getStartingNodeOfTheLoop(node* head) 
{
    if(head == NULL)
        return NULL;

    node* intersection = floydsDetectionLoop(head);

    if(intersection == NULL)
    {
        return NULL;
    }
    node* slow = head;

    while(slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}

void removeLoop(node* head)
{
    if(head == NULL)
    {
        return;
    }
    node* startOfLoop = getStartingNodeOfTheLoop(head);

    if(startOfLoop == NULL)
    {
        return;
    }
    node* temp = startOfLoop;

    while(temp->next != startOfLoop)
    {
        temp = temp->next;
    }
    // Using while loop we will reach to the node whose next pointer will be the starting node of the loop.
    // So, previous node will be pointed to the NULL.
    temp->next = NULL;
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

int main()
{
    int n;
    node* head = NULL;
    node* tail = NULL;

    cout<<"Enter n: ";
    cin>>n;

    getnode(head, tail, n);

    tail->next = head->next;

    if(floydsDetectionLoop(head) != NULL)
    {
        cout<<"Present at "<< getStartingNodeOfTheLoop(head)->data<<endl;
    }
    else
    {
        cout<<"Not present\n";
    }

    // The loop has been removed.
    removeLoop(head);
    traverse(head);

    return 0;
}