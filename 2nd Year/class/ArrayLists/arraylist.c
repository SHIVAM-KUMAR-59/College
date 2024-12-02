#define MAX 5
#include <stdio.h>

// Basic structure
typedef struct {
    int arr[MAX];
    int size;
}arrayList;

// Function to initialize the size
void init(arrayList *a){
    a->size = 0;
}

// Function to insert at last
int insertLast(arrayList *a, int value){
    if (a->size == MAX) {
        printf("The ArrayList is full!\n");
        return 0;
    }else{
        a->arr[a->size] = value;
        a->size++;
        return 1;
    }
}

// Function to delete from the last
int deleteLast(arrayList *a, int *deletedValue){
    if (a->size == 0) {
        printf("The ArrayList is empty!\n");
        return 0;
    }else if(a->size == 1){
       *deletedValue = a->arr[a->size - 1];
       a->size = 0;
       return 1;
    }else{
        *deletedValue = a->arr[a->size - 1];
        a->size --;
       return 1;
    }
}

// Function to display the ArrayList
void display(arrayList *a){
    if(a->size == 0){
        printf("The ArrayList is empty!\n");
    }else{
    printf("The ArrayList is:\n");
    for (int i = 0; i < a->size; i++) {
        printf("%d ", a->arr[i]);
    }
    }
}

int main(){
    arrayList a;
    int d;
    init(&a);
    insertLast(&a, 30);
    insertLast(&a, 30);
    insertLast(&a, 30);
    insertLast(&a, 30);
    insertLast(&a, 30);
    deleteLast(&a, &d);
    printf("%d ",d);
    deleteLast(&a, &d);
    printf("%d ",d);
    deleteLast(&a, &d);
    printf("%d ",d);
    deleteLast(&a, &d);
    printf("%d ",d);
    deleteLast(&a, &d);
    printf("%d ",d);
    display(&a);
    return 0;
}