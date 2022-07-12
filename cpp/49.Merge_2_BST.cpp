/*  You are given two balanced binary search trees of integers having 'N' and 'M' nodes. You have to merge
    the two BSTs into a balanced binary search tree and return the root node to that balanced BST.  */

/*  T.C. -> O(n)
    S.C. -> O(m + n) , where 'm' and 'n' are sizes of inorder list of given two BSTs
*/

/*  We will use the method in which BST is created using inorder list   */

#include<iostream>
#include<vector>
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

vector<int> mergeArray(vector<int> inorder1, vector<int> inorder2)
{
    // vector<int> ans(inorder1.size() + inorder2.size());
    vector<int> ans;

    int i = 0, j = 0;

    while(i < inorder1.size() && j < inorder2.size())
    {
        if(inorder1[i] < inorder2[j])
        {
            ans.push_back(inorder1[i]);
            i++;
        }
        else
        {
            ans.push_back(inorder2[j]);
            j++;
        }
    }

    while(i < inorder1.size())
    {
        ans.push_back(inorder1[i]);
        i++;
    }

    while(j < inorder2.size())
    {
        ans.push_back(inorder2[j]);
        j++;
    }

    return ans;
}

node* inorer_To_BST(int s, int e, vector<int> &inorderValue)
{
    // base case
    if(s > e)
        return NULL;

    int mid = s + (e-s)/2;

    node* newRoot = new node(inorderValue[mid]);

    newRoot->left = inorer_To_BST(s, mid-1, inorderValue);
    newRoot->right = inorer_To_BST(mid+1, e, inorderValue);

    return newRoot;
}

node* mergeBST(node* root1, node* root2)
{
    vector<int> inorder1, inorder2, mergedInorder;

    inorder(root1, inorder1);
    inorder(root2, inorder2);

    mergedInorder = mergeArray(inorder1, inorder2);

    int n = mergedInorder.size() - 1;

    node* ans = inorer_To_BST(0, n, mergedInorder);

    return ans;
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

            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{
    node* root1 = NULL;
    node* root2 = NULL;
    node* mergeRoot = NULL;

    cout<<"Enter the data to create BST 1\n";
    input(root1);
    cout<<endl;

    cout<<"Enter the data to create BST 2\n";
    input(root2);
    cout<<endl;

    // Merging these two BSTs
    mergeRoot = mergeBST(root1, root2);

    levelOrderTraversal(mergeRoot);

    return 0;
}