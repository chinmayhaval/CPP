/*  Construct Tree from Inorder and Preordre

    Given 2 arrays of Inorder and Preorder traversal. Construct a tree and print the Postorder traversal. */

/*  T.C for finding element index in 'in[]' array
    O(1)   */

#include<iostream>
#include<map>
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

void createMap(int in[], map<int, int> &nodeToIndex, int n)
{
    for(int i=0;i<n;i++)
    {
        nodeToIndex[in[i]] = i;    
    }
    
}

node* solve(int in[], int pre[], int &index, int inorderStart, int inorderEnd, int n, map<int, int> &nodeToIndex)
{
    if((index >= n) || (inorderStart > inorderEnd))
    {
        return NULL;
    }

    int element = pre[index++];
    node* temp = new node(element);
    int position = nodeToIndex[element];

    // recursive calls
    temp->left = solve(in, pre, index, inorderStart, position-1, n, nodeToIndex);
    temp->right = solve(in, pre, index, position+1, inorderEnd, n, nodeToIndex);

    return temp;
}

void postOrder(node* root)
{
    // base case
    if(root == NULL)
    {
        return;
    }
    // recursive call
    // L
    postOrder(root->left);
    // R
    postOrder(root->right);
    // N
    cout<<root->data<<" ";
}

int main()
{
    node* root = NULL;

    int in[6] = {3,1,4,0,5,2};
    int pre[6] = {0,1,3,4,2,5};
    int n = 6;
    int preOrderIndex = 0;
    map<int, int> nodeToIndex;

    createMap(in, nodeToIndex, n);

    root = solve(in, pre, preOrderIndex, 0, n-1, n, nodeToIndex);

    postOrder(root);
    cout<<endl;
    return 0;
}