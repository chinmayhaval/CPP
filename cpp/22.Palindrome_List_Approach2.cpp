/*******************
    T.C. -> O(n)
    S.C. -> O(1)
 *******************/

#include<iostream>
#include<vector>
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

node* middleElement(node* head)
{
    node* slow = head;
    node* fast = head->next;

    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
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

bool isPalindrome(node* head)
{
    if(head->next == NULL)
    {
        return true;
    }

    // Finding middle element
    node* middle = middleElement(head);

    // reverse list after middle
    node* temp = middle->next;
    middle->next = reverse(temp);

    // Compare both halves
    node* head1 = head;
    node* head2 = middle->next;

    while(head2 != NULL)
    {
        if(head1->data != head2->data)
        {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    // reverse the List again to avoid the change in real Linked List
    temp = middle->next;
    middle->next = reverse(temp);

    return true;
}

int main()
{
    int n;
    node* head = NULL;
    node* tail = NULL;

    cout<<"How many elements initially is list: ";
    cin>>n;

    getnode(head, tail, n);

    bool ans = isPalindrome(head);

    if(ans)
        cout<<"The List is a Palondrome."<<endl;
    else
        cout<<"The List is not a Palondrome."<<endl;
    return 0;
}
