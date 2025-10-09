#include <stdio.h>
#define INF 9999
#define MAX 30

void dijkstra(int n, int cost[MAX][MAX], int src) {
    int dist[MAX], visited[MAX];
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = -1, min = INF;
        for (int i = 0; i < n; i++)
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }

        visited[u] = 1;

        for (int v = 0; v < n; v++)
            if (!visited[v] && cost[u][v] && cost[u][v] != INF &&
                dist[u] + cost[u][v] < dist[v])
                dist[v] = dist[u] + cost[u][v];
    }

    printf("\nVertex\tDistance from Source\n");
    for (int i = 0; i < n; i++)
        printf("%d\t\t%d\n", i, dist[i]);
}

int main() {
    int n, src;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int cost[MAX][MAX];
    printf("Enter cost adjacency matrix (use 9999 for no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    printf("Enter source vertex: ");
    scanf("%d", &src);

    dijkstra(n, cost, src);
    return 0;
}
