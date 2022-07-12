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
    queue<node*> q;
    int data;

    cout<<"Enter the data for root node: ";
    cin>>data;

    root = new node(data);

    q.push(root);

    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();

        int left;
        cout<<"Enter the data for the left of "<<temp->data<<": ";
        cin>>left;

        if(left != -1)
        {
            temp->left = new node(left);
            q.push(temp->left);
        }

        int right;
        cout<<"Enter the data for the right of "<<temp->data<<": ";
        cin>>right;

        if(right != -1)
        {
            temp->right = new node(right);
            q.push(temp->right);
        }
    }
}

void solve(node* root, int sum, int &maxSum, int len, int &maxLen)
{
    if(root == NULL)
    {
        if(len > maxLen)
        {
            maxLen = len;
            maxSum = sum;
        }
        else if(len == maxLen)
        {
            maxSum = max(sum, maxSum);
        }
        return;
    }

    sum = sum + root->data;

    solve(root->left, sum, maxSum, len+1, maxLen);
    solve(root->right, sum, maxSum, len+1, maxLen);
}

int main()
{
    int len = 0;
    int maxLen = 0;
    int sum = 0;
    int maxSum = INT_MIN;

    node* root = NULL;

    getTree(root);

    solve(root, sum, maxSum, len, maxLen);

    cout<<"The sum of the longest bloodline of tree is: "<<maxSum<<endl;
    return 0;
}