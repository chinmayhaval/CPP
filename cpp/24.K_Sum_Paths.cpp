/*  K Sum Path Problem  */

/*  Given a Binary Tree and an integer K. Find the number of paths in tree which have their sum equal to K.
    A path may start from any node and end at any node in the downward direction.       */

#include<iostream>
#include<queue>
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

void K_sum(node* root, int k, vector<int> path, int &count)
{
    // base case
    if(root == NULL)
        return;

    path.push_back(root->data);

    // left call
    K_sum(root->left, k, path, count);
    // right call
    K_sum(root->right, k, path, count);

    int size = path.size();
    int sum = 0;
    for(int i = size-1;i>=0;i--)
    {
        sum = sum + path[i];
        if(sum == k)
            count++;
    }

    // path.pop_back();
}

int main()
{
    int k;
    vector<int> path;
    int count = 0;
    node* root = NULL;

    getTree(root);

    cout<<"Enter the value of k: ";
    cin>>k;

    K_sum(root, k, path, count);

    cout<<"The answer is: "<<count<<endl;
    return 0;
}