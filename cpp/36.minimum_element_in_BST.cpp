/*  Minimum Element is present at the most left in a BST    */

#include<iostream>
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

int minimum_element(node* root)
{
    node* temp = root;

    while(temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp->data;
}

int main()
{
    node* root = NULL;

    input(root);

    cout<<"The minimum element in BST is "<<minimum_element(root)<<endl;
    return 0;
}