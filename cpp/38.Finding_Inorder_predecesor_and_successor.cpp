/*  Finding inorder predecesor and successor in one code    */

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

void find_element(node* root, int data, node* &pre, node* &suc)
{
    // base condition
    if(root == NULL)
    {
        return;
    }
    
    if(root->data == data)
    {
        if(root->left != NULL)
        {
            node* temp = root->left;
            while(temp->right != NULL)
            {
                temp = temp->right;
            }

            pre = temp;
        }

        if(root->right != NULL)
        {
            node* temp = root->right;
            while (temp->right != NULL)
            {
                temp = temp->right;
            }
            suc = temp;
        }
    }

    // recursive calls
    if(data < root->data)
    {
        suc = root;
        find_element(root->left, data, pre, suc);
    }
    else
    {
        pre = root;
        find_element(root->right, data, pre, suc);
    }
}

int main()
{
    node* root = NULL;
    node* pre = NULL;
    node* suc = NULL;

    input(root);

    int data;
    cout<<"Enter the data whose predecesor and successor you want to find: ";
    cin>>data;

    find_element(root, data, pre, suc);

    cout<<"The inorder predecesor of"<<data<<" is "<<pre->data<<endl;
    cout<<"The inorder successor of"<<data<<" is "<<suc->data<<endl;
    return 0;
}