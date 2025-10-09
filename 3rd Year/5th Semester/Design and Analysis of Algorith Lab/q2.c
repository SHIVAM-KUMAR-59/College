#include <stdio.h>
#define INF 999999

int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int cost[n][n];
    printf("Enter cost adjacency matrix (use 9999 for no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    int visited[n];
    for (int i = 0; i < n; i++) visited[i] = 0;

    int noOfEdges = 1, totalCost = 0;
    visited[0] = 1;

    printf("\nEdges in MST:\n");
    while (noOfEdges < n) {
        int min = INF, a = -1, b = -1;
        for (int i = 0; i < n; i++)
            if (visited[i])
                for (int j = 0; j < n; j++)
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
        if (a != -1 && b != -1) {
            printf("%d - %d : %d\n", a, b, cost[a][b]);
            totalCost += cost[a][b];
            visited[b] = 1;
            noOfEdges++;
        }
    }

    printf("Minimum Cost = %d\n", totalCost);
    return 0;
}
