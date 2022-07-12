/*  Binary Search Tree is a node-based binary tree data structure which has the following properties:

    1. The left subtree of a node contains only nodes with keys lesser than the node’s key.
    2. The right subtree of a node contains only nodes with keys greater than the node’s key.
    3. The left and right subtree each must also be a binary search tree.                       */

#include<iostream>
#include<queue>
using namespace std;

class node
{

    public:
    
    int data;
    node* left;
    node* right;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* insertIntoBST(node* root, int data)
{
    // binary tree is not present
    if(root == NULL)
    {
        root = new node(data);
        return root;
    }

    if(data > root->data)
    {
        root->right = insertIntoBST(root->right, data);
    }
    else
    {
        root->left = insertIntoBST(root->left, data);
    }

    return root;
}

void takeInput(node* &root)
{
    int data;
    cin>>data;

    while(data != -1)
    {
        root = insertIntoBST(root, data);
        cin>>data;
    }
}

void levelOrderTraversal(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();

        if(temp == NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<temp->data<<" ";
            if(temp->left)   // or if(temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}


int main()
{
    node* root = NULL;

    cout<<"Enter the data to create BST: "<<endl;
    takeInput(root);

    cout<<endl;

    levelOrderTraversal(root);

    cout<<endl;
    return 0;
}