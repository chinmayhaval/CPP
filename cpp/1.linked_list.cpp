#include <iostream>
using namespace std;

int counter = 0;

class node
{
public:
    int data;
    node *next;

    // Constructor for creating starting node
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// function to add a new node at the end
void insert_at_end(node *&tail, int data)
{
    // creating the node to add at last
    node *temp = new node(data);
    counter++;
    tail->next = temp;
    tail = temp;
}

// function that will print data of linked list
void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// function to add a new node at the beginning
void insert_at_start(node *&head, int data)
{
    // creating the node to add at the beginning
    node *temp = new node(data);
    counter++;
    temp->next = head;
    head = temp;
}

void insert_at_middle(node *&head, node *&tail, int pos, int data)
{
    // pos is '1' that means we want to add the element at the start
    // so we called the function ''insert_at_start()''.
    if (pos == 1)
    {
        insert_at_start(head, data);
        return;
    }

    node *temp = head;
    int count = 1;

    while (count < pos - 1)
    {
        temp = temp->next;
        count++;
    }
    if(count > counter)
    {
        cout<<"You exceeded the length of linked list!!!"<<endl;
        return;
    }

    // if the position is last that means we want to add the element at the last
    // so we called the function ''insert_at_end()''.
    if (temp->next == NULL)
    {
        insert_at_end(tail, data);
        return;
    }

    // creating a node to add
    node *node_to_insert = new node(data);
    counter++;
    node_to_insert->next = temp->next;
    temp->next = node_to_insert;
}

int main()
{
    // creating a node in heap (dynamically memory allocation)
    node *node1 = new node(10);
    counter++;

    // creating a head that will point beginning node
    // creating a tail that will point last node
    // currently node1 is the beginning node as well as the last node
    node *head = node1;
    node *tail = node1;

    // printing data of linked list
    print(head);

    // adding element at the last
    insert_at_end(tail, 20);

    // adding element at the beginning
    insert_at_start(head, 30);

    // printing the data of the linked list
    print(head);

    // adding element at 2nd position
    insert_at_middle(head, tail, 2, 100);
    print(head);

    // adding element at 1st position means inserting at the start
    insert_at_middle(head, tail, 1, 200);
    print(head);

    // adding element at last position means inserting at the last
    insert_at_middle(head, tail, 7, 300);

    // printing the data of the linked list
    print(head);

    cout<<counter<<endl;
    return 0;
}