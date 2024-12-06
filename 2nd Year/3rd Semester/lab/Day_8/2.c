// Non-Recursive Traversals Methods
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

// Non-Recursive Pre-order Traversal using Stack
void preorderNonRecursive(Node* root) {
    if (root == NULL) return;

    // Create a stack and push the root node
    Node* stack[100];
    int top = -1;
    stack[++top] = root;

    while (top >= 0) {
        Node* temp = stack[top--];
        printf("%d ", temp->data);  // Visit the root

        // Push the right and left child nodes
        if (temp->right) stack[++top] = temp->right;
        if (temp->left) stack[++top] = temp->left;
    }
}

// Non-Recursive In-order Traversal using Stack
void inorderNonRecursive(Node* root) {
    if (root == NULL) return;

    Node* stack[100];
    int top = -1;
    Node* temp = root;

    while (temp || top >= 0) {
        while (temp) {
            stack[++top] = temp;
            temp = temp->left;
        }

        temp = stack[top--];
        printf("%d ", temp->data);  // Visit the root
        temp = temp->right;
    }
}

// Non-Recursive Post-order Traversal using Two Stacks
void postorderNonRecursive(Node* root) {
    if (root == NULL) return;

    Node* stack1[100];
    Node* stack2[100];
    int top1 = -1;
    int top2 = -1;

    stack1[++top1] = root;

    while (top1 >= 0) {
        Node* temp = stack1[top1--];
        stack2[++top2] = temp;

        if (temp->left) stack1[++top1] = temp->left;
        if (temp->right) stack1[++top1] = temp->right;
    }

    while (top2 >= 0) {
        printf("%d ", stack2[top2--]->data);  // Visit the root
    }
}

int main(){
  // Create a sample binary tree
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Pre-order Recursive Traversal: ");
    preorderNonRecursive(root);
    printf("\n");

    printf("In-order Recursive Traversal: ");
    inorderNonRecursive(root);
    printf("\n");

    printf("Post-order Recursive Traversal: ");
    postorderNonRecursive(root);
    printf("\n");
}