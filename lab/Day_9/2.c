#include <stdio.h>
#include <stdlib.h>

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

// Function to find the minimum value node in a BST
struct node* findMin(struct node* node) {
    while (node && node->left != NULL) {
        node = node->left;
    }
    return node;
}

// Function to delete a node in a BST
struct node* deleteNode(struct node* root, int key) {
    if (root == NULL) {
        return root;
    }

    // Traverse the tree to find the node to delete
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node to be deleted is found

        // Case 1: Node with only one child or no child
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 2: Node with two children
        struct node* temp = findMin(root->right); // Get the inorder successor
        root->data = temp->data; // Copy the inorder successor's value to this node
        root->right = deleteNode(root->right, temp->data); // Delete the inorder successor
    }
    return root;
}

// Function to perform inorder traversal (for displaying the tree)
void inorderTraversal(struct node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Function to insert a node in the BST
struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

int main() {
    struct node* root = NULL;

    // Insert nodes into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal of the BST before deletion: ");
    inorderTraversal(root);
    printf("\n");

    int key = 50;
    root = deleteNode(root, key);

    printf("Inorder traversal of the BST after deleting %d: ", key);
    inorderTraversal(root);
    printf("\n");

    return 0;
}
