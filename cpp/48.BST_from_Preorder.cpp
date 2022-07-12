/*  You have been given an array 'PREORDER' representing the preorder traversal of a BST with 'N' nodes. All
    the elements in the given array have distinct values.

    Your task is to construct a binary search tree that matches the given preorder traversal.   */

/*  Optimal Solution with Time Complexity as O(n)       */

#include<iostream>
#include<vector>
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
        left = NULL;
        right = NULL;
    }
};

node* solve(vector<int> &preorder, int mini, int maxi, int &i)
{
    if(i > preorder.size())
        return NULL;

    if(preorder[i] < mini || preorder[i] > maxi)
        return NULL;

    node* root = new node(preorder[i++]);

    root->left = solve(preorder, mini, root->data, i);
    root->right = solve(preorder, root->data, maxi, i);

    return root;
}

node* preorder_to_BST(vector<int> &preorder)
{
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = 0;
    return solve(preorder, mini, maxi, i);
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

            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{
    node* root = NULL;
    vector<int> preorder;

    preorder.push_back(20);
    preorder.push_back(10);
    preorder.push_back(5);
    preorder.push_back(15);
    preorder.push_back(13);
    preorder.push_back(35);
    preorder.push_back(30);
    preorder.push_back(42);

    root = preorder_to_BST(preorder);

    // We created the BST using preorder list
    levelOrderTraversal(root);

    return 0;
}