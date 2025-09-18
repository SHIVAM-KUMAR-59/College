#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight;
    int profit;
    float ratio;
} Item;

int compare(const void *a, const void *b) {
    Item *item1 = (Item *)a;
    Item *item2 = (Item *)b;
    if (item1->ratio < item2->ratio) return 1;
    else if (item1->ratio > item2->ratio) return -1;
    return 0;
}

float getMaxProfit(int weight[], int profit[], int n, int capacity) {
    Item items[n];
    for (int i = 0; i < n; i++) {
        items[i].weight = weight[i];
        items[i].profit = profit[i];
        items[i].ratio = (float)profit[i] / weight[i];
    }

    qsort(items, n, sizeof(Item), compare);

    float maxProfit = 0.0;
    int remainingCapacity = capacity;

    for (int i = 0; i < n; i++) {
        if (items[i].weight <= remainingCapacity) {
            maxProfit += items[i].profit;
            remainingCapacity -= items[i].weight;
        } else {
            maxProfit += items[i].ratio * remainingCapacity;
            break;
        }
    }

    return maxProfit;
}

int main() {
    int weight[] = {10, 40, 20, 30};
    int profit[] = {60, 40, 100, 120};
    int n = sizeof(weight) / sizeof(weight[0]);
    int capacity = 50;

    float maxProfit = getMaxProfit(weight, profit, n, capacity);
    printf("Maximum Profit = %.2f\n", maxProfit);

    return 0;
}

