/*  Construct Tree from Inorder and Preordre

    Given 2 arrays of Inorder and Preorder traversal. Construct a tree and print the Postorder traversal. */

/*  T.C. for finding element index in 'in[]' array
    O(n)
    T.C. of complete code
    O(nlogn)   */

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

int findPosition(int in[], int element, int n)
{
    for(int i=0;i<n;i++)
    {
        if(in[i] == element)
            return i;
    }
    return -1;
}

node* solve(int in[], int pre[], int &index, int inorderStart, int inorderEnd, int n)
{
    if((index >= n) || (inorderStart > inorderEnd))
    {
        return NULL;
    }

    int element = pre[index++];
    node* temp = new node(element);
    int position = findPosition(in, element, n);

    // recursive calls
    temp->left = solve(in, pre, index, inorderStart, position-1, n);
    temp->right = solve(in, pre, index, position+1, inorderEnd, n);

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

    root = solve(in, pre, preOrderIndex, 0, n-1, n);

    postOrder(root);
    cout<<endl;
    return 0;
}