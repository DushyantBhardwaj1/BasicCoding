#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    //constructor

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

void insertAtHead(Node* &head,int data){
    //new node 
    Node* temp=new Node(data);
    temp->next=head;
    head=temp;
}

void print(Node* &head){
    Node* temp=head;
    while(temp != NULL){
        cout<< temp->data<<"    ";
        temp=temp->next;
    }
}
int main()
{
    Node *node1 = new Node(5);
    Node* head=node1;
    insertAtHead(head,10);
    insertAtHead(head,20);
    insertAtHead(head,30);
    insertAtHead(head,40);
    print(head);
}