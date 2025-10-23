// Floyd–Warshall Algorithm (No file or user input)
#include <stdio.h>
#define INF 99999
#define MAX 50

void printMatrix(int n, int dist[MAX][MAX]) {
    printf("Shortest path weight matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("%6s", "INF");
            else
                printf("%6d", dist[i][j]);
        }
        printf("\n");
    }
}

void printPath(int path[MAX][MAX], int u, int v) {
    if (path[u][v] == -1)
        return;
    printPath(path, u, path[u][v]);
    printf(" -> %d", path[u][v] + 1);
}

int main() {
    int n = 5;
    int graph[MAX][MAX] = {
        {0, 3, 8, 0, -4},
        {0, 0, 0, 1, 7},
        {0, 4, 0, 0, 0},
        {2, 0, -5, 0, 0},
        {0, 0, 0, 6, 0}
    };

    int dist[MAX][MAX], path[MAX][MAX];

    // Initialize
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 0 && i != j)
                dist[i][j] = INF;
            else
                dist[i][j] = graph[i][j];

            if (i == j || dist[i][j] == INF)
                path[i][j] = -1;
            else
                path[i][j] = i;
        }
    }

    // Floyd–Warshall algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }
    }

    printMatrix(n, dist);

    int src = 1, dest = 4; // 2 → 5
    printf("\nShortest Path from vertex %d to vertex %d: %d", src + 1, dest + 1, src + 1);
    printPath(path, src, dest);
    printf(" -> %d", dest + 1);

    if (dist[src][dest] == INF)
        printf("\nPath weight: INF\n");
    else
        printf("\nPath weight: %d\n", dist[src][dest]);

    return 0;
}

