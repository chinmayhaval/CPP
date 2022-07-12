/*  Clone a Linked List with next and random pointer    */
/*  You are given a special Linked List with N nodes where each node has a next pointer pointing to its next
    node. You are also given M random pointers, where you will be given M number of pairs denoting two nodes
    a and b i.e. a->arb = b.

    Construct a copy of the given list. The copy should consist of exactly N new nodes, where each new node
    has its value set to the value of its corresponding original node. Both the next and random pointer of
    the new nodes should point to new nodes in the copied list such that the pointers in the original list
    ans copied list represent the same list state. None of the pointers in the new list should point to nodes
    in the original list.

    For example, if there are two nodes X and Y in the original list, where X.random ->Y, then for the
    corresponding two nodes x and y in the copied list, x.random->y.        */

#include<iostream>
#include<unordered_map>
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
    // Step1 -> Create a clone List
    node* cloneHead = NULL;
    node* cloneTail = NULL;
    node* temp = head;

    while(temp != NULL)
    {
        insertAtTail(cloneHead, cloneTail, temp->data);
        temp = temp->next;
    }
    // Step2 -> Create a map
    unordered_map<node*, node*> oldToNewNode;

    node* originalNode = head;
    node* cloneNode = cloneHead;
    while(originalNode != NULL)
    {
        oldToNewNode[originalNode] = cloneNode;
        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }

    originalNode = head;
    cloneNode = cloneHead;

    while(originalNode != NULL)
    {
        cloneNode->random = oldToNewNode[originalNode->random];
        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }
    return cloneHead;
}

int main()
{
    
    return 0;
}