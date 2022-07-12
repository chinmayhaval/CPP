/*  Flatten Binary Tree to Linked List

    Given a Binary Tree, flatten it into linked list in-place. Usage of auxiliary data structure is not
    allowed. After flattening, left of each node should point to NULL and right should contain next node in
    pre-order.
    
    T.C. -> O(n)
    S.C. -> O(1)      */

#include<iostream>
#include<queue>
using namespace std;

class node
{
    public:
    int data;
    node* left;
    node* right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

void getTree(node* &root)
{
    queue<node*> q;
    int d;
    cout<<"Enter the data for root node: ";
    cin>>d;

    root = new node(d);
    q.push(root);

    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();

        int leftd;
        cout<<"Enter the data for the left of "<<temp->data<<": ";
        cin>>leftd;

        if(leftd != -1)
        {
            temp->left = new node(leftd);
            q.push(temp->left);
        }

        int rightd;
        cout<<"Enter the data for the right of "<<temp->data<<": ";
        cin>>rightd;

        if(rightd != -1)
        {
            temp->right = new node(rightd);
            q.push(temp->right);
        }
    }
}

void flattenABinaryTree(node* &root)
{
    node* curr = root;
    
    while(curr != NULL)
    {
        if(curr->left)
        {
            node* pred = curr->left;
            while(pred->right)
            {
                pred = pred->right;
            }
            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}

void traverseBinaryTree(node* root)
{
    node* temp = root;

    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->right;
    }
    cout<<endl;
}

int main()
{
    node* root = NULL;

    getTree(root);

    traverseBinaryTree(root);

    return 0;
}