#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node* left, *right;
    
    Node(int data) {
        key = data;
        left = right = NULL;
    }
};

// Insert a node
Node* insert(Node* node, int key) {
    if (node == NULL) 
        return new Node(key);
    
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    
    return node;
}

// Find the node with the smallest key
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Delete a node
Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }

    return root;
}

// Inorder traversal
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Inorder traversal of the given tree: ";
    inorder(root);
    cout << endl;

    root = deleteNode(root, 20);
    cout << "Inorder traversal after deletion of 20: ";
    inorder(root);
    cout << endl;

    return 0;
}
