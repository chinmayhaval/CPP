/*  Given a BST and an integer 'K'. Your task is to find the 'K-th' smallest element in the given BST. */

/* T.C. -> O(n)     */

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
        data = d;
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

void solve(node* root, int &i, int k)
{
    if(root == NULL)
    {
        return;
    }

    solve(root->left, i, k);
    i++;
    if(i == k)
    {
        cout<<root->data;
        return;
    }
    solve(root->right, i, k);
}

int main()
{
    node* root = NULL;

    input(root);

    int k, i=0;
    cout<<"Enter the value of k: ";
    cin>>k;

    cout<<"The smallest K-th element is ";
    solve(root, i, k);
    cout<<endl;

    return 0;
}