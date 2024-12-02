
//1. WAP to create a function which takes two values and return back the addition of two values
//2. WAP to create a function which takes one value and change the value of it
//3. WAP to create a function and return sum and average of two numbers
//4. WAP to create a structure containing the sum and value and return the structure of two numbers
//5. WAP to create a structure containing the marks of 3 subjects and create a function that calculates the average

#include <stdio.h>
#include <stdlib.h>

struct student {
    int a, b, c;
    float average;
};

struct student calculate(int a, int b, int c) {
    struct student op;
    op.a = a;
    op.b = b;
    op.c = c;
    op.average = (float)(a + b + c) / 3.0;
    return op;
}

int main() {

    int a = rand() % 100;
    int b = rand() % 100;
    int c = rand() % 100;
    struct student answer = calculate(a, b, c);
    printf("The marks are: %d, %d and %d, and their average is: %.2f\n", answer.a, answer.b, answer.c, answer.average);
    return 0;
}