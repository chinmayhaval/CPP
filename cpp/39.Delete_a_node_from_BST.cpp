/*  When we delete a node, three posibilities arises:

    1.  node to be deleted is the leaf: Simply remove from the tree.
    2.  node to be deleted has one child: Copy the child to the node and delete the child.
    3.  node to be deleted has two children: Find inorder successor of the node. Copy the contents of the
        inorder successor to the node and delete the inorder successor. Note that inorder predecesor can also
        be used.        
                                                            */

/*  T.C. -> O(n)    */


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

node* inorder_successor(node* root)
{
    if(root == NULL)
        return NULL;

    node* temp = root;

    while(temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

node* delete_Element(node* root, int data)
{
    // base case
    if(root == NULL)
    {
        return root;
    }

    if(root->data == data)
    {
        // 0 child
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // 1 child
        // for left child
        if(root->left != NULL && root->right == NULL)
        {
            node* temp = root->left;
            delete root;
            return temp;
        }

        // for right child
        if(root->right != NULL && root->left == NULL)
        {
            node* temp = root->right;
            delete root;
            return temp;
        }

        // 2 children
        if(root->left != NULL && root->right != NULL)
        {
            // we would use inorder successor
            node* mini = inorder_successor(root->right);
            root->data = mini->data;
            root->right = delete_Element(root->right, mini->data);
            return root;
        }
    }

    // recursive calls
    if(root->data > data)
    {
        root->left = delete_Element(root->left, data);
    }
    else
    {
        root->right = delete_Element(root->right, data);
    }
    return root;
}

void levelOrderTraversal(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();

        if(temp == NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<temp->data<<" ";
            if(temp->left)   // or if(temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{
    node* root = NULL;

    // creating a tree
    input(root);

    int data;
    cout<<"Enter the data you want to delete from the BST: ";
    cin>>data;

    root = delete_Element(root, data);

    levelOrderTraversal(root);
    
    return 0;
}