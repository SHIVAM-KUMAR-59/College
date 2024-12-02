#include <stdio.h>
#include <stdlib.h>

// Definition of the tree node structure
struct node {
    int data;
    struct node *left, *right;
};

// Function to create a new node
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to search for a key in a binary tree
int search(struct node* root, int key) {
    if (root == NULL) {
        return 0; // Key not found
    }

    if (root->data == key) {
        return 1; // Key found
    }

    // Recursively search in the left and right subtrees
    int foundInLeftSubtree = search(root->left, key);
    if (foundInLeftSubtree) {
        return 1;
    }
    
    return search(root->right, key); // Check in the right subtree
}

// Function to insert nodes into the binary tree for testing
struct node* insertLeft(struct node* root, int data) {
    root->left = createNode(data);
    return root->left;
}

struct node* insertRight(struct node* root, int data) {
    root->right = createNode(data);
    return root->right;
}

int main() {
    // Creating a sample binary tree
    struct node* root = createNode(1);
    struct node* node2 = insertLeft(root, 2);
    struct node* node3 = insertRight(root, 3);
    insertLeft(node2, 4);
    insertRight(node2, 5);
    insertLeft(node3, 6);
    insertRight(node3, 7);

    int key = 5;
    if (search(root, key)) {
        printf("Key %d found in the binary tree.\n", key);
    } else {
        printf("Key %d not found in the binary tree.\n", key);
    }

    return 0;
}
