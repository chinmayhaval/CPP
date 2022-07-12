/*  There is a Binary Tree consisting of 'N' nodes. Each node of this BST has some integer data

    You are given a pointer to the root node of this BST, and an integer 'X', Print "True" if there is a
    node in BST having data equals to 'X', otherwise print "False".     */

/*  Since Recursion uses stacks, due to formation of stacks, S.C. goes O(n).    */

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

node* createBST(node* root, int data)
{
    if(root == NULL)
    {
        root = new node(data);
        return root;
    }

    if(data > root->data)
    {
        root->right = createBST(root->right, data);
    }
    else
    {
        root->left = createBST(root->left, data);
    }

    return root;
}

void input(node* &root)
{
    int data;
    cout<<"Enter the data elements to create a Binary Search Tree\n";
    cin>>data;

    while(data != -1)
    {
        root = createBST(root, data);
        cin>>data;
    }
}

bool SearchInBST(node* root, int x)
{
    if(root == NULL)
        return false;

    if(root->data == x)
        return true;

    // searching in left part
    if(x < root->data)
    {
        return SearchInBST(root->left, x);
    }
    // searching in right part
    else
    {
        return SearchInBST(root->right, x);
    }
}

int main()
{
    node* root = NULL;

    input(root);

    int x;
    cout<<"Searching Element: ";
    cin>>x;

    if(SearchInBST(root, x))
        cout<<"True"<<endl;
    else
    {
        cout<<"False"<<endl;
    }

    return 0;
}