#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// Define the structure of a node in the binary tree
struct tree_node {
    int data;
    struct tree_node *right, *left;
};

// Structure for stack nodes (to store tree nodes)
struct stack_node {
    struct tree_node *treePtr;
    struct stack_node *next;
};

// Structure for stacks
typedef struct {
    struct stack_node *top;
    int count;
} stack;

// Function to initialize the stack
void init(stack *s) {
    s->top = NULL;
    s->count = 0;
}

// Function to push a tree node onto the stack
int push(stack *s, struct tree_node *val) {
    if (s->count == 5) {  // Limiting stack size to 5 for this example
        printf("Stack Overflow!\n");
        return 1;
    }
    struct stack_node *curr = (struct stack_node *)malloc(sizeof(struct stack_node));
    if (curr == NULL) {
        printf("Memory Allocation Failed!\n");
        return 1;
    }
    curr->treePtr = val;
    curr->next = s->top;
    s->top = curr;
    s->count++;
    return 0;
}

// Function to pop and return a tree node from the stack
int pop(stack *s, struct tree_node **result) {
    if (s->top == NULL) {
        printf("Stack Underflow!\n");
        return 1;
    }
    *result = s->top->treePtr;
    struct stack_node *temp = s->top;
    s->top = s->top->next;
    free(temp);
    s->count--;
    return 0;
}

// Function to check if the stack is empty
bool isEmpty(stack s) {
    return s.top == NULL;
}

// Globally Declare stack
stack s;

// Pre-Order Traversal using the stack
/*
Approach:

1. Push the root node to the stack
2. While the stack is not empty
    1. Pop the top node
    2. Print the popped node
    3. Push the right and left children of the popped node to the stack

Time Complexity: O(n)
*/
void PreOrderTraversal(struct tree_node *root){
    push(&s, root);
    struct tree_node *ptr;
    while(!isEmpty(s)){
        pop(&s, &ptr);
        printf("%d ", ptr->data);
        if(ptr->right != NULL){
            push(&s, ptr->right);
        }
        if(ptr->left != NULL){
            push(&s, ptr->left);
        }
    }
}

// In-Order Traversal using the stack
/*
Approach:

1. Take a temporary pointer to root
2. Move the temporary pointer to the extreme left node and push every node to the stack
3. While the stack is not empty
    1. Pop the top node
    2. Print the popped node
    3. Move the temporary pointer to the extreme right node .
    4. Set the right of the displayed node as temporary node and againmove towards the left.
*/
void InOrderTraversal(struct tree_node *root){

    struct tree_node *current = root;
    while(current != NULL){
        push(&s, current);
        current = current->left;
    }
    struct tree_node *ptr;
    while(!isEmpty(s)){
        pop(&s, &ptr);
        printf("%d ", ptr->data);
        current = ptr->right;
        while(current != NULL){
            push(&s, current);
            current = current->left;
        }
    }
}

// Post-Order Traversal using the stack
/*
Approach:

1. Take a temporary pointer to root say current
2. Push the current and current->right to the stack
3. Go to the extreme left
4. While the stack is not empty
    1. Pop the top node
    2. If the right of the popped node is not NULL, then print the popped node
    3. If the right node exists, check if the stack is empty or not
    4. If the stack is empty then display the popped node
    5. If the stack is not empty, pop another node
    6. If the newly popped node is on the right of the previously popped node, push the previously popped node into the stack
    7. If the newly popped node is on the right of the previously popped node, push the previously popped node into the stack and display the newly popped node
*/
void PostOrderTraversal(struct tree_node *root) {
    if (root == NULL) return;
    struct tree_node *current = root;
    struct tree_node *lastVisited = NULL;

    do {
        // Traverse to the leftmost node
        while (current != NULL) {
            push(&s, current);
            current = current->left;
        }

        struct tree_node *topNode;
        pop(&s, &topNode);

        // If the right child is NULL or already visited
        if (topNode->right == NULL || topNode->right == lastVisited) {
            printf("%d ", topNode->data);  // Print the node
            lastVisited = topNode;         // Mark it as visited
            current = NULL;                // Prevent further left traversal
        } else {
            // Otherwise, process the right subtree
            push(&s, topNode);  // Re-push the top node
            current = topNode->right;  // Move to the right subtree
        }

    } while (!isEmpty(s));
}


int main(){

    init(&s); // Initialize the stack

    // Manually create the binary tree and allocate memory for each node
    struct tree_node *root = (struct tree_node*)malloc(sizeof(struct tree_node));
    struct tree_node *node10 = (struct tree_node*)malloc(sizeof(struct tree_node));
    struct tree_node *node20 = (struct tree_node*)malloc(sizeof(struct tree_node));
    struct tree_node *node30 = (struct tree_node*)malloc(sizeof(struct tree_node));
    struct tree_node *node40 = (struct tree_node*)malloc(sizeof(struct tree_node));
    struct tree_node *node50 = (struct tree_node*)malloc(sizeof(struct tree_node));
    struct tree_node *node60 = (struct tree_node*)malloc(sizeof(struct tree_node));

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
    PreOrderTraversal(root);
    printf("\n");

    printf("Inorder Traversal: \n");
    InOrderTraversal(root);
    printf("\n");

    printf("Postorder Traversal: \n");
    PostOrderTraversal(root);
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
