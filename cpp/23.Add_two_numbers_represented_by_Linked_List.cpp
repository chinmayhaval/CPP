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

node* reverse(node* head)
{
    node* curr = head;
    node* prev = NULL;
    node* next = NULL;

    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void insertAtHead(node* &head, node* &tail, int digit)
{
    node* temp = new node(digit);

    if(head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    else
    {
        tail->next = temp;
        tail = temp;
        return;
    }
}

node* add(node* head1, node* head2)
{
    int carry = 0;
    node* ansHead = NULL;
    node* ansTail = NULL;

    while(head1 != NULL && head2 != NULL)
    {
        int sum = carry + head1->data + head2->data;
        int digit = sum%10;
        insertAtHead(ansHead, ansTail, digit);
        carry = sum/10;

        head1 = head1->next;
        head2 = head2->next;
    }

    while(head1 != NULL)
    {
        int sum = carry + head1->data;
        int digit = sum%10;
        getnode(ansHead, ansTail, digit);
        carry = sum/10;

        head1 = head1->next;
    }
    while(head2 != NULL)
    {
        int sum = carry + head2->data;
        int digit = sum%10;
        getnode(ansHead, ansTail, digit);
        carry = sum/10;

        head2 = head2->next;
    }

    while(carry != 0)
    {
        int sum = carry;
        int digit = sum%10;
        getnode(ansHead, ansTail, digit);
        carry = sum/10;
    }
    return ansHead;
}

node* addTwoLists(node* head1, node* head2)
{
    // step1-> reverse input L.L.
    head1 = reverse(head1);
    head2 = reverse(head2);

    // step2-> add 2 L.L.
    node* ans = add(head1, head2);

    // step3-> reverse 'ans' and return
    ans = reverse(ans);
    return ans;
}


int main()
{
    node* head1 = NULL;
    node* head2 = NULL;
    node* tail1 = NULL;
    node* tail2 = NULL;
    int n;

    cout<<"Enter the number of nodes for L.L.1: ";
    cin>>n;

    getnode(head1, tail1, n);

    cout<<"Enter the number of nodes for L.L.2: ";
    cin>>n;

    getnode(head2, tail2, n);

    node* ans = addTwoLists(head1, head2);

    cout<<"The sum of two linked lists is: ";
    traverse(ans);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
    return 0;
}