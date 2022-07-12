/*
You are given a binary tree with 'N' nodes. Your task is to return the size of the largest subtree of the
binary tree which is also a BST.
*/
/*
T.C -> O(n)
*/
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
        left = NULL;
        right = NULL;
    }
};

class info
{
    public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};

// Building a binary tree from level order
void levelOrderTraversal(node* &root)
{
    queue<node*> q;

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

info solve(node* root, int &maxSize)
{
    // base case
    if(root == NULL)
    {
        return {INT_MIN, INT_MAX, true, 0};
    }

    info left = solve(root->left, maxSize);
    info right = solve(root->right, maxSize);

    info currNode;

    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(root->data, right.maxi);
    currNode.mini = min(root->data, left.mini);

    if(left.isBST && right.isBST && (left.maxi < root->data && right.mini > root->data))
    {
        currNode.isBST = true;
    }
    else
    {
        currNode.isBST = false;
    }

    if(currNode.isBST)
    {
        maxSize = max(maxSize, currNode.size);
    }

    return currNode;
}

int largestBST(node* root)
{
    int maxSize = 0;

    info temp = solve(root, maxSize);

    return maxSize;
}

int main()
{
    node* root = NULL;

    levelOrderTraversal(root);

    // finding the size of a valid BST in binary tree
    int ans = largestBST(root);

    cout<<"\nThe size of the largest BST is: "<<ans<<endl;

    return 0;
}