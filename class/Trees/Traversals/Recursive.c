// Traversals in C

#include<stdio.h>
#include<stdlib.h>

// Define the structure of a node in the binary tree
struct node {
    int data;
    struct node *right, *left;
};

// Preorder traversal function
void PreorderTraversal(struct node *root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
}

// Inorder traversal function
void InorderTraversal(struct node *root) {
    if (root == NULL) {
        return;
    }

    InorderTraversal(root->left);
    printf("%d ", root->data);
    InorderTraversal(root->right);
}

// Postorder traversal function
void PostorderTraversal(struct node *root) {
    if (root == NULL) {
        return;
    }

    PostorderTraversal(root->left);
    PostorderTraversal(root->right);
    printf("%d ", root->data);
}

int main() {
    // Manually create the binary tree and allocate memory for each node
    struct node *root = (struct node*)malloc(sizeof(struct node));
    struct node *node10 = (struct node*)malloc(sizeof(struct node));
    struct node *node20 = (struct node*)malloc(sizeof(struct node));
    struct node *node30 = (struct node*)malloc(sizeof(struct node));
    struct node *node40 = (struct node*)malloc(sizeof(struct node));
    struct node *node50 = (struct node*)malloc(sizeof(struct node));
    struct node *node60 = (struct node*)malloc(sizeof(struct node));

    // Assign values to the nodes
    root->data = 1;
    root->left = node10;
    root->right = node20;

    node10->data = 10;
    node10->left = NULL;
    node10->right = NULL;

    node20->data = 20;
    node20->left = node30;
    node20->right = node40;

    node30->data = 30;
    node30->left = node60;
    node30->right = node50;

    node40->data = 40;
    node40->left = NULL;
    node40->right = NULL;

    node50->data = 50;
    node50->left = NULL;
    node50->right = NULL;

    node60->data = 60;
    node60->left = NULL;
    node60->right = NULL;

    // Perform traversals
    printf("Preorder Traversal: \n");
    PreorderTraversal(root);
    printf("\n");

    printf("Inorder Traversal: \n");
    InorderTraversal(root);
    printf("\n");

    printf("Postorder Traversal: \n");
    PostorderTraversal(root);
    printf("\n");

    // Free the allocated memory (optional, but good practice)
    free(root);
    free(node10);
    free(node20);
    free(node30);
    free(node40);
    free(node50);
    free(node60);

    return 0;
}
