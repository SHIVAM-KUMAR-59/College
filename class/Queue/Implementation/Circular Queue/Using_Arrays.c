// Circular Queue helps us to perfectly manage space along with time complexity

#define MAX 100
#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int arr[MAX];
    int front, rear;
}queue;

// Function to initialize
void init(queue *q){
    q->front = q->rear = -1;
}

// Function to push
int push(queue *q, int val){
    if ((q->rear + 1) % MAX == q->front) {
        printf("Queue is full\n");
        return 1;
    }
    if(q->rear == -1){
        q->rear = 0;
        q->front = 0;
        q->arr[q->rear] = val;
    }else{
        q->rear = (q->rear + 1) % MAX;
        q->arr[q->rear] = val;
    }
    return 0;
}

// Function to pop
int pop(queue *q, int *val){
    if (q->front == -1) {
        printf("Queue is empty\n");
        return 1;
    }
    *val = q->arr[q->front];
    if(q->front = q->rear){
        q->front = q->rear = -1;
    }else{
        q->front = (q->front + 1) % MAX;
    }
    return 0;
}

int main(){
    queue q;
    init(&q);
    push(&q, 10);
    push(&q, 20);
    push(&q, 40);
    push(&q, 30);
    int n;
    pop(&q, &n);
    if(n){ // Check if there is some value present in n
    printf("Popped Value: %d", n);
    }else{
            printf("Unsuccessfull\n");
     }
    return 0;
}