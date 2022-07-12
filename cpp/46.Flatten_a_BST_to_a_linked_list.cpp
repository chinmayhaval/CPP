/*  You have been given a Binary Search Tree. Your task is to flatten the given BST to a sorted list. More
    formally, you have to make a right skewed BST from the given BST, i.e., the left child of all the nodes
    must be NULL and the value at the right child must be greater than the current node.    */

/*  T.C. -> O(n)
    S.C. -> O(n)    */

#include<iostream>
#include<vector>
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

void traverse(node* &head)
{
    node* temp = head;

    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->right;
    }
    cout<<endl;
}

node* flatten(node* root)
{
    vector<int> inorderValue;

    inorder(root, inorderValue);

    int n = inorderValue.size();

    node* newRoot = new node(inorderValue[0]);
    node* curr = newRoot;

    // making left part of all nodes as NULL and connecting right part to the greater node
    for(int i=1;i<n;i++)
    {
        node* temp = new node(inorderValue[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }

    // Making left and right part of last node (or greatest node) as NULL
    curr->left = NULL;
    curr->right = NULL;

    return newRoot;
}

int main()
{
    node* root = NULL;

    // Creating a BST
    input(root);

    // Now, flatten the BST and return root of Linked List
    node* newRoot = flatten(root);

    // Traversing Linked List
    traverse(newRoot);
    
    return 0;
}