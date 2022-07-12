#include<iostream>
#include<queue>
#include<climits>
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

node* ancestor(node* root, int &k, int d)
{
    if(root == NULL)
        return NULL;
    if(root->data == d)
        return root;

    node* leftAns = ancestor(root->left, k, d);
    node* rightAns = ancestor(root->right, k, d);

    if(leftAns != NULL && rightAns == NULL)
    {
        k--;
        if(k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    
    if(leftAns == NULL && rightAns != NULL)
    {
        k--;
        if(k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
}

int main()
{
    node* root = NULL;

    getTree(root);

    cout<<"Enter the kth ancestor: ";
    int k;
    cin>>k;

    cout<<"Enter the data for which you want to find out kth ancestor: ";
    int d;
    cin>>d;

    node* ans = ancestor(root, k, d);

    if(ans == NULL || ans->data == d)
    {
        cout<<"answer doesn't exist!!!"<<endl;
    }
    else
    {
        cout<<"The answer is: "<<ans->data<<endl;
    }
    return 0;
}