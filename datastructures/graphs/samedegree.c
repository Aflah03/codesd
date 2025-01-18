#include <stdio.h>

#define MAX_NODES 100

int isRegularGraph(int graph[MAX_NODES][MAX_NODES], int nodes) {
    int degree[MAX_NODES] = {0};

    // Calculate the degree of each node
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            if (graph[i][j] == 1) {
                degree[i]++;
            }
        }
    }

    // Check if all nodes have the same degree
    for (int i = 1; i < nodes; i++) {
        if (degree[i] != degree[0]) {
            return 0; // Graph is not regular
        }
    }
    return 1; // Graph is regular
}

int main() {
    int nodes, edges;
    int graph[MAX_NODES][MAX_NODES] = {0};

    printf("Enter the number of nodes: ");
    scanf("%d", &nodes);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (node1 node2):\n");
    for (int i = 0; i < edges; i++) {
        int node1, node2;
        scanf("%d %d", &node1, &node2);
        graph[node1][node2] = 1;
        graph[node2][node1] = 1; // Since the graph is undirected
    }

    if (isRegularGraph(graph, nodes)) {
        printf("The graph is regular.\n");
    } else {
        printf("The graph is not regular.\n");
    }

    return 0;
}
