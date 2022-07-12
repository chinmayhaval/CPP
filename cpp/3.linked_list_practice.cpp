#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    // Constructor
    node(int data){
        this->data = data;
        this->next = NULL;
    }
};

// function to add the node at the beginning
void insert_at_the_beginning(node* &head, int data){
    node* temp = new node(data);
    temp->next = head;
    head = temp;
}

// function to add the node at the end
void insert_at_the_end(node* &tail, int data){
    node* temp = new node(data);
    tail->next = temp;
    tail = temp;
}

// function to add the node at a random position
void insert_at_the_middle(node* &head, node* &tail, int pos, int data){
    int count = 1;
    node* temp = head;

    // suppose the position passed is '1'
    if(pos == 1){
        insert_at_the_beginning(head, data);
        return;
    }

    while(count<pos-1){
        temp = temp->next;
        count++;
    }

    // suppose the position passed is the last position
    if(temp->next == NULL){
        insert_at_the_end(tail, data);
        return;
    }

    // Now, for the middle position or the position other than start and end
    node* new_node = new node(data);
    new_node->next = temp->next;
    temp->next = new_node;
}

// function to print the node
void print_the_node(node* &head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}


int main(){
    // created a node
    node* node1 = new node(10);
    // creating a head that will point starting node
    node* head = node1;
    // creating a tail that will point ending node
    node* tail = node1;
    // adding a new node at the beginning
    insert_at_the_beginning(head, 5);
    // adding a new node at the end
    insert_at_the_end(tail, 20);
    insert_at_the_end(tail, 50);
    // adding a new node at the random position
    insert_at_the_middle(head, tail, 3, 100);
    // to print the node
    print_the_node(head);
    return 0;
}