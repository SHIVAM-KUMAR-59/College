
// Recursive Traversals Methods
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Recursive Pre-order Traversal
void preorderRecursive(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);  // Visit the root
    preorderRecursive(root->left);  // Traverse the left subtree
    preorderRecursive(root->right);  // Traverse the right subtree
}

// Recursive In-order Traversal
void inorderRecursive(Node* root) {
    if (root == NULL) return;
    inorderRecursive(root->left);  // Traverse the left subtree
    printf("%d ", root->data);  // Visit the root
    inorderRecursive(root->right);  // Traverse the right subtree
}

// Recursive Post-order Traversal
void postorderRecursive(Node* root) {
    if (root == NULL) return;
    postorderRecursive(root->left);  // Traverse the left subtree
    postorderRecursive(root->right);  // Traverse the right subtree
    printf("%d ", root->data);  // Visit the root
}

int main() {
    // Create a sample binary tree
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Pre-order Recursive Traversal: ");
    preorderRecursive(root);
    printf("\n");

    printf("In-order Recursive Traversal: ");
    inorderRecursive(root);
    printf("\n");

    printf("Post-order Recursive Traversal: ");
    postorderRecursive(root);
    printf("\n");

    return 0;
}


