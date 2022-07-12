/*  Lowest Common Ancestor in a Binary Tree

    Given a Binary Tree with all unique values and two nodes value, n1 and n2. The task is to find the 
    Lowest Common Ancestor of the given two nodes. We may assume that either both n1 and n2 are present
    in a tree or none of them are present.  */

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
    queue<node*>  q;
    int data;
    cout<<"Enter the data for the root node: ";
    cin>>data;

    root = new node(data);
    q.push(root);

    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();

        int leftdata;
        cout<<"Enter the data for the left of "<<temp->data<<": ";
        cin>>leftdata;

        if(leftdata != -1)
        {
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

        int rightdata;
        cout<<"Enter the data for the right of "<<temp->data<<": ";
        cin>>rightdata;

        if(rightdata != -1)
        {
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}

node* lca(node* root, int n1, int n2)
{
    if(root == NULL)
        return NULL;

    if(root->data == n1 || root->data == n2)
    {
        return root;
    }

    node* leftAns = lca(root->left, n1, n2);
    node* rightAns = lca(root->right, n1, n2);

    if(leftAns != NULL && rightAns != NULL)
    {
        return root;
    }
    else if(leftAns != NULL && rightAns == NULL)
    {
        return leftAns;
    }
    else if(leftAns == NULL && rightAns != NULL)
    {
        return rightAns;
    }
    else
    {
        return NULL;
    }
}

int main()
{
    
    return 0;
}