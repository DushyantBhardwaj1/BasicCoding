#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    //constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    ~Node()
    {
        int val = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "memory free for node with data " << val << endl;
    }
};
int getLengthNode(Node* head){
    Node* temp=head;
    int length=0;
    while(temp!=NULL){
        length++;
        temp=temp->next;
    }
    return length;
}
void deleteNode(Node* &head, int d) {
    if (head == NULL) return;  // Empty list case

    Node* temp = head;

    // If the node to be deleted is the head node
    if (temp->data == d) {
        head = head->next;
        if (head != NULL) head->prev = NULL; // Update the new head's prev pointer
        delete temp;
        return;
    }

    // Traverse the list to find the node to delete
    while (temp != NULL && temp->data != d) {
        temp = temp->next;
    }

    // If the node was not found
    if (temp == NULL) return;

    // Adjust the pointers of the neighboring nodes
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    // Delete the node
    delete temp;
}

void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void insertAtHead(Node* &head,int data){
    Node* temp= new Node(data);
    temp->next=head;
    head->prev=temp;
    head=temp;
}
void insertAtTail(Node* &tail,int data){
    Node* temp= new Node(data);
    tail->next=temp;
    tail=temp;
}
void insertAtPosition(Node* &head,Node* &tail,int data,int position){
    if(position==1){
        insertAtHead(head,data);
        return;
    }
    
    Node* temp=head;
    int cnt=1;
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL){
        insertAtTail(tail,data);
        return;
    }
    Node * nodeToInsert= new Node(data);
    temp->next->prev=nodeToInsert;
    nodeToInsert->next=temp->next;
    temp->next=nodeToInsert;
    nodeToInsert->prev=temp;
}
int main()
{
    Node* node1=new Node(10);
    Node* head=node1;
    Node* tail=node1;
    print(head);   
    insertAtHead(head,11);
    print(head);
    insertAtHead(head,12);
    print(head);
    insertAtHead(head,13);
    print(head);
    insertAtHead(head,14);
    print(head);
    insertAtHead(head,15);
    print(head);
    insertAtTail(tail,9);
    print(head);
    insertAtTail(tail,8);
    print(head);
    insertAtTail(tail,7);
    print(head);
    deleteNode(head,13);
    print(head);
    deleteNode(head,15);
    print(head);

}

