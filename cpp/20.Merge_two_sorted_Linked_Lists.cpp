/*  The algorithm we are going to use is worth to impress the interviewer   */
/*  The algorithm is a little bit complexed but well optimized. */

/*  You are given two sorted Linked Lists. You have to merge them to produce a combined sorted Linked List.
    You need to return the head of the final Linked List.   */


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

node* solve(node* head1, node* head2)
{

    // if only one element is present in head1 Linked List
    if(head1->next == NULL)
    {
        head1->next = head2;
        return head1;
    }
    node* curr1 = head1;
    node* next1 = curr1->next;
    node* curr2 = head2;
    node* next2 = NULL;

    while(next1 != NULL && curr2 != NULL)
    {
        if((curr2->data >= curr1->data) && (curr2->data <= next1->data))
        {
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;
            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
            curr1 = next1;
            next1 = next1->next;

            if(next1 == NULL)
            {
                curr1->next = curr2;
                return head1;
            }
        }
    }
    return head1;
}

node* sortTwoLinkedLists(node* head1, node* head2)
{
    if(head1 == NULL)
    {
        return head2;
    }
    if(head2 == NULL)
    {
        return head1;
    }

    if(head1->data <= head2->data)
    {
        solve(head1, head2);
        return head1;
    }
    else
    {
        solve(head2, head1);
        return head2;
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


int main()
{
    int n1,n2;

    node* head1 = NULL;
    node* tail1 = NULL;
    node* head2 = NULL;
    node* tail2 = NULL;

    cout<<"Enter the number of nodes you want initially for the Linked List 1: ";
    cin>>n1;

    getnode(head1, tail1, n1);

    cout<<"Enter the number of nodes you want initially for the Linked List 2: ";
    cin>>n2;

    getnode(head2, tail2, n2);

    cout<<"The merged Sorted Linked List is\n";

    node* ans = sortTwoLinkedLists(head1, head2);
    traverse(ans);
    return 0;
}