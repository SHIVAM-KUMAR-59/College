/*
Write a function to search an element in an arraylist and deletethat
element in that arraylist (You need to create the arraylist insidethestructure) .
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int arr[10];
    int size;
} arraylist;

// Function to initialize the arraylist
void init(arraylist *a) {
    a->size = 0;
}

// Function to fill the arraylist with random values
void fill(arraylist *a, int n) {
    if (n > 10) {
        printf("Maximum size of arraylist is 10\n");
        return;
    }
    a->size = n;
    for (int i = 0; i < n; i++) {
        a->arr[i] = rand() % 100;
    }
}

// Function to search and delete an element
void delete(arraylist *a, int val) {
    int i = 0;
    while (i < a->size && a->arr[i] != val) {
        i++;
    }
    if (i >= a->size) {  // If element is not found
        printf("Element not found in arraylist\n");
        exit(1);
    } else {
        for (int j = i; j < a->size - 1; j++) {
            a->arr[j] = a->arr[j + 1];
        }
        a->size--;  // Reduce size of the array
    }
}

// Function to display the arraylist
void display(arraylist *a) {
    if (a->size == 0) {
        printf("The ArrayList is empty!\n");
    }
    else if(a->size > 10){
        printf("Maximum size of arraylist is 10\n");
    } else {
        printf("The ArrayList is:\n");
        for (int i = 0; i < a->size; i++) {
            printf("%d ", a->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    arraylist a;
    init(&a);
    
    int n;
    printf("Enter the number of elements to insert: ");
    scanf("%d", &n);

    fill(&a, n);
    display(&a);

    int val;
    printf("Enter the element to delete: ");
    scanf("%d", &val);

    delete(&a, val);
    display(&a);

    return 0;
}
