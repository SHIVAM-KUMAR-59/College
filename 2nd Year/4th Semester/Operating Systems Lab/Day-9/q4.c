#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct node {
    int value;
    struct node *left;
    struct node *right;
};

void *fun(void *arg) {
    int a = *((int *)arg);

    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->value = a;
    node->left = NULL;
    node->right = NULL;

    if (a > 1) {
        pthread_t left, right;
        int val = a / 2;

        struct node *leftAns;
        pthread_create(&left, NULL, fun, &val);
        pthread_join(left, (void **)&leftAns);
        node->left = leftAns;

        struct node *rightAns;
        pthread_create(&right, NULL, fun, &val);
        pthread_join(right, (void **)&rightAns);
        node->right = rightAns;
    }

    return node;
}


void postOrder(struct node *root) {
    if (root == NULL) {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->value);
}


int main() {
    pthread_t t;
    int a = 8;
    struct node *root = NULL;

    pthread_create(&t, NULL, fun, &a);
    pthread_join(t, (void **)&root);

    printf("\nPost-order Traversal: ");
    postOrder(root);
    printf("\n");

    return 0;
}
