#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node *&head, int data)
{
    // new node
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void insertAtValue(Node *&head, int data,int key)
{
    Node *temp = new Node(data);
    Node* temp1 = head;
    while(temp->data!=key){
        temp=temp->next;
    }
    temp->next=temp1->next;
    temp1->next=temp;
}
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "-->  ";
        temp = temp->next;
    }
}
int main()
{
    Node *node1 = new Node(5);
    Node *head = node1;
    Node *tail = node1;
    insertAtHead(head, 10);
    insertAtHead(head, 20);
    insertAtHead(head, 30);
    insertAtHead(head, 40);
    insertAtTail(tail, 4);
    insertAtTail(tail, 3);
    insertAtTail(tail, 2);
    insertAtValue(head,6,40);
    print(head);
}