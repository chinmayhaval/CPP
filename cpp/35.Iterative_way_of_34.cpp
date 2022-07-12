/*  There is a Binary Tree consisting of 'N' nodes. Each node of this BST has some integer data

    You are given a pointer to the root node of this BST, and an integer 'X', Print "True" if there is a
    node in BST having data equals to 'X', otherwise print "False".     */

/*  In Iterative way, there is no formation of stacks due to which S.C. goes O(1)  */

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
    cout<<"Enter the data elements to create a Binary Tree\n";
    cin>>data;

    while(data != -1)
    {
        root = createBST(root, data);
        cin>>data;
    }
}

bool SearchInBST(node* root, int x)
{
    node* temp = root;

    while(temp != NULL)
    {
        if(x == temp->data)
            return true;

        if(x < temp->data)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return false;
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