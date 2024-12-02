#include <stdio.h>
#include <stdlib.h>

#define ARRAYLIST_SIZE 10

struct arraylist {
    int *arr;
    int cs;
    int max_size;
};

// Function to initiate
void initArrayList(struct arraylist *a, int size) {
    a->arr = (int *)malloc(size * sizeof(int));
    if (a->arr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    a->cs = 0;
    a->max_size = size;
}

// Function to insert
int insert(struct arraylist *a, int num, int ind) {
    if (a->cs == a->max_size) {
        printf("ArrayList is full\n");
        return 1;
    }
    if (ind > a->cs) {
        ind = a->cs;
    }
    for (int i = a->cs; i > ind; i--) {
        a->arr[i] = a->arr[i - 1];
    }
    a->arr[ind] = num;
    a->cs++;
    return 0;
}

// Function for modified insert
int modified_insert(struct arraylist *a, int num, int ind, int fat) {
    if (a->cs + fat > a->max_size) {
        printf("Not enough space to insert %d elements\n", fat);
        return 1;
    }
    if (ind > a->cs) {
        ind = a->cs;
    }
    for (int i = a->cs - 1; i >= ind; i--) {
        a->arr[i + fat] = a->arr[i];
    }
    for (int i = 0; i < fat; i++) {
        a->arr[ind + i] = num;
    }
    a->cs += fat;
    return 0;
}

// Function for modified delete
int modified_delete(struct arraylist *a, int ind, int fat) {
    if (ind >= a->cs || ind < 0) {
        printf("Index out of bounds\n");
        return 1;
    }
    if (ind + fat > a->cs) {
        printf("Invalid deletion range\n");
        return 1;
    }
    for (int i = ind; i < a->cs - fat; i++) {
        a->arr[i] = a->arr[i + fat];
    }
    a->cs -= fat;
    return 0;
}

// Function to delete
int delete(struct arraylist *a, int ind) {
    if (a->cs == 0) {
        printf("ArrayList is empty\n");
        return 1;
    }
    if (ind >= a->cs || ind < 0) {
        printf("Invalid index\n");
        return 1;
    }
    for (int i = ind; i < a->cs - 1; i++) {
        a->arr[i] = a->arr[i + 1];
    }
    a->cs--;
    return 0;
}

// Function to delete all continuous instances of a number starting at a given index
int delete_all_continuous_instances(struct arraylist *a, int ind) {
    // Check if the index is within bounds
    if (ind < 0 || ind >= a->cs) {
        printf("Index out of bounds\n");
        return 1;
    }

    int num = a->arr[ind];  // Number to delete
    int start = ind;        // Start of the contiguous sequence to delete
    int end = ind;          // End of the contiguous sequence to delete

    // Find the start of the contiguous sequence going backwards
    while (start > 0 && a->arr[start - 1] == num) {
        start--;
    }

    // Find the end of the contiguous sequence going forwards
    while (end < a->cs - 1 && a->arr[end + 1] == num) {
        end++;
    }

    // Number of elements to be deleted
    int shift = end - start + 1;

    // Shift the elements to the left to remove the sequence
    for (int i = start; i < a->cs - shift; i++) {
        a->arr[i] = a->arr[i + shift];
    }

    // Update the current size of the arraylist
    a->cs -= shift;
    return 0;
}


// Function to copy one arraylist into another
void copy(struct arraylist *a, struct arraylist *b) {
    if (b->max_size < a->cs) {
        printf("Destination ArrayList does not have enough capacity\n");
        return;
    }
    for (int i = 0; i < a->cs; i++) {
        b->arr[i] = a->arr[i];
    }
    b->cs = a->cs;
}

// Function to display
void display(struct arraylist a) {
    if (a.cs == 0) {
        printf("ArrayList is empty\n");
    } else {
        printf("Data in ArrayList: ");
        for (int i = 0; i < a.cs; i++) {
            printf("%d ", a.arr[i]);
        }
        printf("\n");
    }
}

// Function to free the memory of the arraylist
void freeArrayList(struct arraylist *a) {
    free(a->arr);
    a->arr = NULL;
    a->cs = 0;
    a->max_size = 0;
}

int main() {
    struct arraylist a;
    struct arraylist b;
    
    initArrayList(&a, ARRAYLIST_SIZE); 
    initArrayList(&b, ARRAYLIST_SIZE); 
    
    modified_insert(&a,5,0,3);
    modified_insert(&a,2,3,2);

    printf("\nAfter initial insertion:\n");
    display(a);

    delete_all_continuous_instances(&a, 1);
    printf("\nAfter deleting continuous instances at index 1:\n");
    display(a);

    copy(&a, &b);
    printf("\nCopied ArrayList b from a:\n");
    display(b);

    freeArrayList(&a);
    freeArrayList(&b);

    return 0;
}
