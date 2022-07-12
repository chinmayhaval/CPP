/*  Merge sort is preferred for the Linked Lists and quickSort is preferred for the arrays.   */

/*********************
    T.C. -> O(nlogn) 
    S.C. -> O(1)     
 *********************/

#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* next;
    node* random;

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

node* findMid(node* &head)
{
    node* slow = head;
    node* fast = head->next;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node* merge(node* &left , node* &right)
{
    if(left == NULL)
    {
        return right;
    }
    if(right == NULL)
    {
        return left;
    }

    node* ans = new node(-1);
    node* temp = ans;

    while(left != NULL && right != NULL)
    {
        if(left->data < right->data)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while(left != NULL)
    {
        temp->next = left;
        temp = left;
        left = left->next;
    }

    while(right != NULL)
    {
        temp->next = right;
        temp = right;
        right = right->next;
    }

    ans = ans->next;
    return ans;
}

node* mergeSort(node* &head)
{
    // base case
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    node* mid = findMid(head);

    node* left = head;
    node* right = mid->next;
    mid->next = NULL;

    // recursive calls to sort both halves
    left = mergeSort(left);
    right = mergeSort(right);

    // merge both left and right halves
    node* result = merge(left, right);
    return result;
}

int main()
{
    node* head = NULL;
    node* tail = NULL;
    int n;

    cout<<"Enter the number of nodes initially: ";
    cin>>n;

    getnode(head, tail, n);

    cout<<"\nThe L.L. before sorting\n";
    traverse(head);

    cout<<"\nThe L.L. after sorting\n";
    node* ans = mergeSort(head);
    traverse(ans);
    return 0;
}