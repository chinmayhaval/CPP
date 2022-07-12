/*  In this solution: */

/*****************
    T.C. -> O(n)
    S.C. -> O(1)
 *****************/

/*  Optimized Solution  */


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

void insertAtTail(node* &head, node* &tail, int d)
{
    node* newnode = new node(d);
    if(head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    else
    {
        tail->next = newnode;
        tail = newnode;
    }
}

node* copyList(node* head)
{
    // step1: create a clone List
    node* cloneHead = NULL;
    node* cloneTail = NULL;
    node* temp = head;
    while(temp != NULL)
    {
        insertAtTail(cloneHead, cloneTail, temp->data);
        temp = temp->next;
    }

    // step2: cloneList add inbetween original List
    node* originalNode = head;
    node* cloneNode = cloneHead;

    while(originalNode != NULL && cloneNode != NULL)
    {
        node* next = originalNode->next;
        originalNode->next = cloneNode;
        originalNode = next;

        next = cloneNode->next;
        cloneNode->next = originalNode;
        cloneNode = next;
    }

    // step3: random pointer copy
    temp = head;
    while(temp != NULL)
    {
        if(temp->next != NULL)
        {
            temp->next->random = temp->random ? temp->random->next : temp->random;
        }
        temp = temp->next->next;
    }

    // step4: revert changes in step2
    originalNode = head;
    cloneNode = cloneHead;
    while(originalNode != NULL && cloneNode != NULL)
    {
        originalNode->next = cloneNode->next;
        originalNode = originalNode->next;

        if(originalNode != NULL)
        {
        cloneNode->next = originalNode->next;
        }
        cloneNode = cloneNode->next;
    }

    // step5: return ans
    return cloneHead;
}

int main()
{
    
    return 0;
}