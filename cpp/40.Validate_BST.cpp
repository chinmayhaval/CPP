/*  We have to check whether a tree is a valid BST or not   */

/*  T.C. -> O(n)
    S.C. -> O(n)    */

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

void buildTreeFromLevelOrder(node* &root)
{
    queue<node*> q;
    int data;
    cout<<"Enter data for root: ";
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();

        int leftdata;
        cout<<"Enter left node for "<<temp->data<<endl;
        cin>>leftdata;

        if(leftdata != -1)
        {
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

        int rightdata;
        cout<<"Entr right node for "<<temp->data<<endl;
        cin>>rightdata;

        if(rightdata != -1)
        {
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}

bool valid_BST(node* root, int min, int max)
{
    if(root == NULL)
        return true;

    if(root->data > min && root->data < max)
    {
        bool left = valid_BST(root->left, min, root->data);
        bool right = valid_BST(root->right, root->data, max);
        return (left && right);
    }
    else
    {
        return false;
    }
}

int main()
{
    node* root = NULL;
    int min = INT_MIN;
    int max = INT_MAX;

    buildTreeFromLevelOrder(root);

    bool ans = valid_BST(root, min, max);

    if(ans)
        cout<<"The tree is a valid BST.\n";
    else
        cout<<"The tree is not a valid BST.\n";

    return 0;
}