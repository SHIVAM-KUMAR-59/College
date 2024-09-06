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

int main(){
    queue q;
    init(&q);
    push(&q, 10);
    push(&q, 20);
    return 0;
}