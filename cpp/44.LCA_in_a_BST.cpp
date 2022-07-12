/*  You are given a binary search tree of integers with N nodes. You are also given references to two nodes
    P and Q from this BST.

    Your task is to find the lowest common ancestor(LCA) of these two given nodes.      */

/*  We are going to use recursion   */

#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* left;
    node* right;

    node(int d)
    {
        d = data;
        left = NULL;
        right = NULL;
    }
};

node* createTree(node* root, int data)
{
    if(root == NULL)
    {
        root = new node(data);
        return root;
    }

    if(data < root->data)
    {
        root->left = createTree(root->left, data);
    }
    else
    {
        root->right = createTree(root->right, data);
    }
    return root;
}

void input(node* &root)
{
    int data;
    cout<<"Enter the elements to create a BST\n";
    cin>>data;

    while(data != -1)
    {
        root = createTree(root, data);
        cin>>data;
    }
}

node* solve(node* root, int P, int Q)
{
    if(root == NULL)
        return NULL;

    if(root->data < P && root->data < Q)
    {
        return solve(root->right, P, Q);
    }

    if(root->data > P && root->data > Q)
    {
        return solve(root->left, P, Q);
    }

    return root;
}

int main()
{
    node* root = NULL;
    int P, Q;

    // Creating the BST
    input(root);

    cout<<"Enter P and Q: ";
    cin>>P>>Q;

    node* ans = solve(root, P, Q);

    cout<<"Ans: "<<ans->data<<endl;
    return 0;
}