#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;

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

void print(Node* head){
    Node* temp=head;
    while(temp->next!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void insertAtHead(Node*head,int data){
    Node* temp= new Node(data);
    temp->prev=head;
    

}
int main()
{
}