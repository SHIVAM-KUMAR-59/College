#include <stdio.h>
#include <stdlib.h>

#define MAX 30

typedef struct {
    int u, v, w;
} Edge;

int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent, parent[i]);
}

void unionSet(int parent[], int rank[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);

    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

int main() {
    int n, e;
    printf("Enter number of vertices and edges: ");
    scanf("%d%d", &n, &e);

    Edge edges[MAX];
    printf("Enter edges (u v w):\n");
    for (int i = 0; i < e; i++)
        scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w);

    // Sort edges by weight
    for (int i = 0; i < e - 1; i++)
        for (int j = 0; j < e - i - 1; j++)
            if (edges[j].w > edges[j + 1].w) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }

    int parent[MAX], rank[MAX];
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int cost = 0, edge_count = 0;
    printf("\nEdges in MST:\n");
    for (int i = 0; i < e && edge_count < n - 1; i++) {
        int u = find(parent, edges[i].u);
        int v = find(parent, edges[i].v);
        if (u != v) {
            printf("%d - %d : %d\n", edges[i].u, edges[i].v, edges[i].w);
            cost += edges[i].w;
            unionSet(parent, rank, u, v);
            edge_count++;
        }
    }

    printf("Minimum Cost = %d\n", cost);
    return 0;
}
