/*
Write a program that will create an ascending element array fromthe given unsorted array by fulfilling the following criteria. The values present in the resultant array may be different fromthe original array but the digits present in the each element of theoriginal array must be present in the same position of the
resultant array. Your target should be to minimize the maximumvalue present inthe resultant array. Ex: Original array: 2,9,6,3,9,8,17,3,4,6,13,5
Resultant array: 2, 9, 16, 23, 29, 38, 71, 73, 74, 76, 103, 105
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_DIGITS 10 // Assuming maximum of 10 digits in a number

typedef struct {
    int digits[MAX_DIGITS];
    int min_val;
} DigitPattern;

int compare_digit_patterns(const void *a, const void *b) {
    DigitPattern *p1 = (DigitPattern *)a;
    DigitPattern *p2 = (DigitPattern *)b;
    for (int i = 0; i < MAX_DIGITS; i++) {
        if (p1->digits[i] != p2->digits[i]) {
            return p1->digits[i] - p2->digits[i];
        }
    }
    return 0;
}

void create_ascending_array(int arr[], int n, int result[]) {
    DigitPattern patterns[n];
    int num_patterns = 0;

    // Find unique digit patterns and their minimum possible values
    for (int i = 0; i < n; i++) {
        int num = arr[i];
        int j = MAX_DIGITS - 1;
        while (num > 0) {
            patterns[num_patterns].digits[j--] = num % 10;
            num /= 10;
        }
        while (j >= 0) {
            patterns[num_patterns].digits[j--] = 0;
        }
        patterns[num_patterns].min_val = 0;
        num_patterns++;
    }

    // Sort digit patterns
    qsort(patterns, num_patterns, sizeof(DigitPattern), compare_digit_patterns);

    // Assign minimum values to digit patterns
    int min_val = 1;
    for (int i = 0; i < num_patterns; i++) {
        patterns[i].min_val = min_val;
        min_val = min_val * 10 + 1;
    }

    // Create the result array
    for (int i = 0; i < n; i++) {
        int num = 0;
        for (int j = 0; j < MAX_DIGITS; j++) {
            num = num * 10 + patterns[i].digits[j];
        }
        result[i] = num + patterns[i].min_val - 1;
    }
}

int main() {
    int arr[] = {2, 9, 6, 3, 9, 8, 17, 3, 4, 6, 13, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result[n];

    create_ascending_array(arr, n, result);

    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}