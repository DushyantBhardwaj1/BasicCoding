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

    // descructor
    ~Node()
    {
        int value = this->data;
        
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
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

void insertAtValue(Node *&head, Node *&tail, int data, int key)
{
    Node *temp = new Node(data);
    Node *temp1 = head;
    while (temp1->data != key)
    {
        temp1 = temp1->next;
    }
    if (temp1 == head)
    {
        insertAtHead(head, data);
        return;
    }
    if (temp1 == tail)
    {
        insertAtTail(head, data);
        return;
    }
    temp->next = temp1->next;
    temp1->next = temp;
}

void insertAtPosition(Node *&head, Node *&tail, int data, int position)
{
    if (position == 1)
    {
        insertAtHead(head, data);
        return;
    }
    Node *temp = new Node(data);
    Node *temp1 = head;
    int cnt = 1;
    // agar n per daalna hai to n-1 tek jaana hoga
    while (cnt < position - 1)
    {
        temp1 = temp1->next;
        cnt++;
    }
    if (temp1 == tail)
    {
        insertAtTail(tail, data);
        return;
    }
    temp->next = temp1->next;
    temp1->next = temp;
}

void deleteAtPosition(Node *&head, Node *&tail, int position)
{
    Node *curr = head;
    Node *prev=NULL;
    

    if (position == 1)
    {
        head = head->next;
        curr->next=NULL;
        delete curr;
        return;
    }
    int cnt = 1;
    while (cnt < position)
    {
        prev=curr;
        curr = curr->next;
        cnt++;
    }
    prev->next=curr->next;
    curr->next=NULL;
    delete curr;
}
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    Node *node1 = new Node(5);
    Node *head = node1;
    Node *tail = node1;
    print(head);
    insertAtHead(head, 10);
    insertAtHead(head, 20);
    print(head);
    insertAtTail(tail, 4);
    print(head);
    insertAtValue(head, tail, 6, 10);
    print(head);
    insertAtPosition(head, tail, 100, 3);
    insertAtPosition(head, tail, 200, 1);
    insertAtPosition(head, tail, 300, 8);
    print(head);
    insertAtTail(tail, 400);
    print(head);
    deleteAtPosition(head,tail,1);
    deleteAtPosition(head,tail,2);
    print(head);
}