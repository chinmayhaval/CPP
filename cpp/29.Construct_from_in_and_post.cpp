#include<iostream>
#include<queue>
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
        nodeToIndex[in[i]] = i;
}

node* solve(int in[], int post[], int n, int &index, map<int, int> &nodeToIndex, int inorderStart, int inorderEnd)
{
    // base case
    if(index <= 0 || inorderStart > inorderEnd)
        return NULL;

    int element = post[index--];
    node* temp = new node(element);
    int position = nodeToIndex[element];

    // recursive calls
    temp->right = solve(in, post, n, index, nodeToIndex, position+1, inorderEnd);
    temp->left = solve(in, post, n, index, nodeToIndex, inorderStart, position -1);

    return temp;
}

void preOrder(node* root)
{
    // base case
    if(root == NULL)
    {
        return;
    }
    // recursive call
    // N
    cout<<root->data<<" ";
    // L
    preOrder(root->left);
    // R
    preOrder(root->right);
}

int main()
{
    node* root = NULL;
    int in[8] = {4, 8, 2, 5, 1, 6, 3, 7};
    int post[8] = {8, 4, 5, 2, 6, 7, 3, 1};
    int n = 8;
    int postOrderIndex = n-1;

    map<int, int> nodeToIndex;
    createMap(in, nodeToIndex, n);

    root = solve(in, post, n, postOrderIndex, nodeToIndex, 0, n-1);

    preOrder(root);
    cout<<endl;

    return 0;
}