/*  Burning Tree

    Given a binary tree and a node called target. Find the minimum time required to burn the completely
    binary tree if the target is set on fire. It is known that in 1 second all nodes connected to a given
    node get burned. That is its left child, right child, and parent.       */


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

void getTree(node* &root)
{
    queue<node*> q;
    int d;
    cout<<"Enter the data for root node: ";
    cin>>d;

    root = new node(d);
    q.push(root);

    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();

        int leftd;
        cout<<"Enter the data for the left of "<<temp->data<<": ";
        cin>>leftd;

        if(leftd != -1)
        {
            temp->left = new node(leftd);
            q.push(temp->left);
        }

        int rightd;
        cout<<"Enter the data for the right of "<<temp->data<<": ";
        cin>>rightd;

        if(rightd != -1)
        {
            temp->right = new node(rightd);
            q.push(temp->right);
        }
    }
}

node* createParentMapping(node* root, int target, map<node*, node*> &nodeToParent)
{
    node* targetNode = NULL;

    queue<node*> q;
    q.push(root);
    nodeToParent[root] = NULL;

    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();

        if(temp->data == target)
            targetNode = temp;

        if(temp->left)
        {
            nodeToParent[temp->left] = temp;
            q.push(temp->left);
        }

        if(temp->right)
        {
            nodeToParent[temp->right] = temp;
            q.push(temp->right);
        }
    }
    return targetNode;
}

int burnTree(node* root, map<node*, node*> &nodeToParent, node* targetNode)
{
    map<node*, bool> visited;
    queue<node*> q;

    q.push(targetNode);
    visited[targetNode] = true;
    int ans = 0;

    while(!q.empty())
    {
        bool flag = 0;
        int size = q.size();

        for(int i=0;i<size;i++)
        {
            node* temp = q.front();
            q.pop();

            if(temp->left && !visited[temp->left])
            {
                flag = true;
                q.push(temp->left);
                visited[temp->left] = true;
            }

            if(temp->right && !visited[temp->right])
            {
                flag = true;
                q.push(temp->right);
                visited[temp->right] = true;
            }

            if(nodeToParent[temp] && !visited[nodeToParent[temp]])
            {
                flag = true;
                q.push(nodeToParent[temp]);
                visited[nodeToParent[temp]] = true;
            }
        }

        if(flag == 1)
            ans++;
    }
    return ans;
}

int main()
{
    node* root = NULL;

    getTree(root);

    // Creating a map variable to connect current node to its parent node
    map<node*, node*> nodeToParent;

    // Target Node
    int target;
    cout<<"Enter the target node: ";
    cin>>target;

    // This function will find target node in the tree and also create the mapping of current node with its parent node.
    node* targetNode = createParentMapping(root, target, nodeToParent);

    // This function will burn the tree and find the time to completely burn the tree
    int ans = burnTree(root, nodeToParent, targetNode);

    cout<<"Ans: "<<ans<<endl;

    return 0;
}