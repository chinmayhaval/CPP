/*  You have been given a binary search tree of integers with 'N' nodes. Your task is to convert it into a
    balanced BST with the minimum height possible.  */

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

void inorder(node* root, vector<int> &inorderValue)
{
    // base case
    if(root == NULL)
        return;

    // left part
    inorder(root->left, inorderValue);
    // storing root data in vector
    inorderValue.push_back(root->data);
    // right part
    inorder(root->right, inorderValue);
}

// In this recursion function, we passed vector as a reference so that it may not take 'n' spaces.
// Passing vector as a reference will make Space Complexity as O(1).
// Otherwise, it will bring TLE (Time Limit Exceeded).
node* rec(int s, int e, vector<int> &inorderValue)
{
    // base case
    if(s > e)
        return NULL;

    int mid = s + (e-s)/2;

    node* newRoot = new node(inorderValue[mid]);

    newRoot->left = rec(s, mid-1, inorderValue);
    newRoot->right = rec(mid+1, e, inorderValue);

    return newRoot;
}

node* normal_to_balanced(node* root)
{
    vector<int> inorderValue;

    inorder(root, inorderValue);

    int n = inorderValue.size() - 1;

    // Calling recursion to make BST using inorder array
    node* temp = rec(0, n, inorderValue);

    return temp;
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

    // Creating BST
    input(root);

    // Converting the BST into Balanced BST
    root = normal_to_balanced(root);

    // Calling Level Order Traversal to check whether the BST has been converted into Balanced BST or not
    levelOrderTraversal(root);

    return 0;
}