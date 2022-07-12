/*  You have been given a Binary Search Tree and a target value. You need to find out whether there exists
    a pair of node values in the BST such that their sum is equal to the target value.  */

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

bool solve(node* root, int target)
{
    vector<int> inorderValue;

    // storing inorder data in a vector
    inorder(root, inorderValue);

    int i = 0;
    int j = inorderValue.size() - 1;
    int sum = 0;

    while(i < j)
    {
        sum = inorderValue[i] + inorderValue[j];

        if(sum == target)
        {
            return true;
        }

        if(sum < target)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return false;
}

int main()
{
    node* root = NULL;
    int target;

    // creating a Binary Search Tree
    input(root);

    // Taking target value as input
    cout<<"Enter the target value: ";
    cin>>target;

    // checking whether a pair exists with sum equal to target value
    bool ans = solve(root, target);

    if(ans)
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;

    return 0;
}