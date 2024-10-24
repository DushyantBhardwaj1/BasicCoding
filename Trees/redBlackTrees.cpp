#include <iostream>
using namespace std;

enum Color { RED, BLACK };

class Node {
public:
    int data;
    bool color;
    Node *left, *right, *parent;

    Node(int data) {
        this->data = data;
        left = right = parent = NULL;
        this->color = RED;
    }
};

// Class to represent a Red-Black Tree
class RBTree {
private:
    Node* root;

protected:
    void rotateLeft(Node*&, Node*&);
    void rotateRight(Node*&, Node*&);
    void fixViolation(Node*&, Node*&);

public:
    RBTree() { root = NULL; }
    void insert(const int &n);
    void inorder();
    Node* getRoot();
    void deleteNode(int data);
    void deleteFix(Node*&);
    Node* BSTDelete(Node*& root, int data);
    Node* minValueNode(Node* node);
    void inorderHelper(Node* root);
};

Node* RBTree::getRoot() {
    return root;
}

void RBTree::rotateLeft(Node*& root, Node*& pt) {
    Node* pt_right = pt->right;
    pt->right = pt_right->left;

    if (pt->right != NULL)
        pt->right->parent = pt;

    pt_right->parent = pt->parent;

    if (pt->parent == NULL)
        root = pt_right;
    else if (pt == pt->parent->left)
        pt->parent->left = pt_right;
    else
        pt->parent->right = pt_right;

    pt_right->left = pt;
    pt->parent = pt_right;
}

void RBTree::rotateRight(Node*& root, Node*& pt) {
    Node* pt_left = pt->left;
    pt->left = pt_left->right;

    if (pt->left != NULL)
        pt->left->parent = pt;

    pt_left->parent = pt->parent;

    if (pt->parent == NULL)
        root = pt_left;
    else if (pt == pt->parent->left)
        pt->parent->left = pt_left;
    else
        pt->parent->right = pt_left;

    pt_left->right = pt;
    pt->parent = pt_left;
}

void RBTree::fixViolation(Node*& root, Node*& pt) {
    Node* parent_pt = NULL;
    Node* grand_parent_pt = NULL;

    while ((pt != root) && (pt->color != BLACK) && (pt->parent->color == RED)) {
        parent_pt = pt->parent;
        grand_parent_pt = pt->parent->parent;

        if (parent_pt == grand_parent_pt->left) {
            Node* uncle_pt = grand_parent_pt->right;

            if (uncle_pt != NULL && uncle_pt->color == RED) {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            } else {
                if (pt == parent_pt->right) {
                    rotateLeft(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
                rotateRight(root, grand_parent_pt);
                swap(parent_pt->color, grand_parent_pt->color);
                pt = parent_pt;
            }
        } else {
            Node* uncle_pt = grand_parent_pt->left;

            if (uncle_pt != NULL && uncle_pt->color == RED) {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            } else {
                if (pt == parent_pt->left) {
                    rotateRight(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
                rotateLeft(root, grand_parent_pt);
                swap(parent_pt->color, grand_parent_pt->color);
                pt = parent_pt;
            }
        }
    }
    root->color = BLACK;
}

void RBTree::insert(const int &data) {
    Node* pt = new Node(data);
    if (root == NULL) {
        pt->color = BLACK;
        root = pt;
    } else {
        Node* parent = NULL;
        Node* temp = root;
        while (temp != NULL) {
            parent = temp;
            if (pt->data < temp->data)
                temp = temp->left;
            else if (pt->data > temp->data)
                temp = temp->right;
            else
                return;
        }
        pt->parent = parent;
        if (pt->data < parent->data)
            parent->left = pt;
        else
            parent->right = pt;
        fixViolation(root, pt);
    }
}

Node* RBTree::minValueNode(Node* node) {
    Node* temp = node;
    while (temp->left != NULL)
        temp = temp->left;
    return temp;
}

void RBTree::inorderHelper(Node* root) {
    if (root == NULL)
        return;
    inorderHelper(root->left);
    cout << root->data << " ";
    inorderHelper(root->right);
}

void RBTree::inorder() {
    inorderHelper(root);
    cout << endl;
}

int main() {
    RBTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(15);

    cout << "Inorder traversal of the Red-Black Tree: ";
    tree.inorder();
    return 0;
}
