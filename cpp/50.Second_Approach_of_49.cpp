/*  T.C. -> O(n)
    S.C. -> O(h1 + h2) , where 'h1' and 'h2' are heights of two BSTs
*/


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

void convert_into_sorted_doubly_Linked_List(node* root, node* head)
{
    // base case
    if(root == NULL)
    return;

    convert_into_sorted_doubly_Linked_List(root->right, head);
    root->right = head;

    if(head != NULL)
        head->left = root;

    head = root;

    convert_into_sorted_doubly_Linked_List(root->left, head);
}

node* merge_Linked_List(node*  head1, node* head2)
{
    node* head = NULL;
    node* tail = NULL;

    while(head1 != NULL && head2 != NULL)
    {
        if(head1->data < head2->data)
        {
            if(head == NULL)
            {
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else
            {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else
        {
            if(head == NULL)
            {
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else
            {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    while(head1 != NULL)
    {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while(head2 != NULL)
    {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    return head;
}

int countNodes(node* head)
{
    int count = 0;

    node* temp = head;

    while(temp != NULL)
    {
        count++;
        temp = temp->right;
    }
    return count;
}

node* Linked_List_to_BST(node* head, int n)
{
    // base case
    if(n <= 0 || head == NULL)
    {
        return NULL;
    }

    node* left = Linked_List_to_BST(head, n/2);

    node* root = head;
    root->left = left;

    head = head->right;

    root->right = Linked_List_to_BST(head, n/2 - 1);

    return root;
}

node* merge_2_BST(node* root1, node* root2)
{
    node* head1 = NULL;
    node* head2 = NULL;

    convert_into_sorted_doubly_Linked_List(root1, head1);
    head1->left = NULL;

    convert_into_sorted_doubly_Linked_List(root2, head2);
    head2->left = NULL;

    /*
    merging two DLL and returning its head
    */
    node* head = merge_Linked_List(head1, head2);

    int n = countNodes(head);

    node* ans = Linked_List_to_BST(head, n);

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
    node* newRoot = NULL;

    cout<<"Enter elements for BST 1\n";
    input(root1);
    cout<<endl;

    cout<<"Enter elements for BST 2\n";
    input(root2);
    cout<<endl;

    newRoot = merge_2_BST(root1, root2);

    levelOrderTraversal(newRoot);

    return 0;
}