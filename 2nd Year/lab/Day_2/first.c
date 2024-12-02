
// Create two float array dynamically 
#include<stdio.h>
#include<stdlib.h>
int main(){
    float *a= calloc(3 , sizeof(float)); // declaration
    float *b = calloc(5 , sizeof(float));
    // Taking input for first array
    for(int i = 0; i < 3; i++){
        *(a+i) = rand()%100;
    }

    // Taking input for second array
    for(int i = 0; i < 5; i++){
        *(b+i) = rand()%100;
    }

    // Printing first array
    printf("values in first: \n");
    for(int i = 0; i < 3; i++){
        printf("%f ", *(a+i));
    }
    printf("\n");

    // Printing second array
    printf("values in second: \n");
    for(int i = 0; i < 5; i++){
        printf("%f ", *(b+i));
    }
    printf("\n");

    // copying values
    a = realloc(a, 8 * sizeof(float));
    for(int i = 3; i < 8; i++){
        *(a+i) = *(b+i-3);
    }

    // printing combined array
    printf("combined array: \n");
    for(int i = 0; i < 8; i++){
        printf("%f ", *(a+i));
    }
    return 0;
}