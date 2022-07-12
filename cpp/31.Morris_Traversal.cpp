/*  Morris Traversal is an in-order traversal that doesn't use an extra space or auxiliary data structure.

    T.C. -> O(n)
    S.C. -> O(1)
                        */


#include<iostream>
#include<queue>
using namespace std;

/*  class to create nodes  */
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

/*  Finction to construct a Binary Tree using Level Order Traversal  */
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

/* Function to traverse the binary tree without recursion and without stack */
void MorrisTraversal(node* root)
{
	node *current, *pre;

	if (root == NULL)
		return;

	current = root;
	while (current != NULL)
    {

		if (current->left == NULL)
        {
			cout << current->data << " ";
			current = current->right;
		}
		else {

			/* Find the inorder predecessor of current */
			pre = current->left;
			while (pre->right != NULL && pre->right != current)
				pre = pre->right;

			/* Make current as the right child of its inorder predecessor */
			if (pre->right == NULL)
            {
				pre->right = current;
				current = current->left;
			}

			/* Revert the changes made in the 'if' part to restore the original tree i.e., fix the right child of predecessor */
			else
            {
				pre->right = NULL;
				cout << current->data << " ";
				current = current->right;
			}
		}
	}
}

int main()
{
	node* root = NULL;

    getTree(root);

	MorrisTraversal(root);

    cout<<endl;

	return 0;
}


