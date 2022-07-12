/*  Maximum sum of non-adjacent nodes

    Given a binary tree with a value associated with each node, we need to choose a subset of these nodes
    such that sum of chosen nodes is maximum under a constraint that no two chosen node in subset should
    be directly connected that is, if we have taken a node in our sum then we can't take its any children
    or parents in consideration and vice versa.     */

#include<iostream>
#include<queue>
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

pair<int, int> solve(node* root)
{
    if(root == NULL)
    {
        pair<int, int> p;
        p = make_pair(0,0);
        return p;
    }

    pair<int, int> left = solve(root->left);
    pair<int, int> right = solve(root->right);

    pair<int, int> res;

    res.first = root->data + left.second + right.second;

    res.second = max(left.first, left.second) + max(right.first, right.second);

    return res;
}

int main()
{
    node* root = NULL;
    getTree(root);

    pair<int, int> ans;
    ans = solve(root);

    cout<<"Ans: "<<max(ans.first, ans.second)<<endl;
    return 0;
}