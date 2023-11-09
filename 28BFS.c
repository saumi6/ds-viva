#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 50

typedef struct {
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices, numEdges;
} Graph;

typedef struct {
    int queue[MAX_VERTICES];
    int front, rear;
} Queue;

void initializeGraph(Graph *g) {
    g->numVertices = 0;
    g->numEdges = 0;
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            g->adjacencyMatrix[i][j] = 0;
        }
    }
}

void addEdge(Graph *g, int source, int destination) {
    g->adjacencyMatrix[source][destination] = 1;
    g->numEdges++;
}

int isQueueEmpty(Queue q) {
    return (q.front == -1);
}

void enqueue(Queue *q, int element) {
    q->rear++;
    q->queue[q->rear] = element;
    if (q->front == -1) {
        q->front = 0;
    }
}

int dequeue(Queue *q) {
    int element = q->queue[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return element;
}

void bfs(int rootNode, Graph g, int visited[]) {
    Queue q;
    q.front = q.rear = -1;
    enqueue(&q, rootNode);
    visited[rootNode] = 1;
    while (q.front != -1) {
        int x = dequeue(&q);
        printf("%d ", x);
        for (int i = 0; i < g.numVertices; i++) {
            if (g.adjacencyMatrix[x][i] == 1 && visited[i] != 1) {
                enqueue(&q, i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    Graph graph;
    int root, source, destination;
    initializeGraph(&graph);
    printf("Enter the number of vertices for the directed graph: ");
    scanf("%d", &graph.numVertices);
    printf("Enter the number of edges for the directed graph: ");
    scanf("%d", &graph.numEdges);
    for (int i = 1; i <= graph.numEdges; i++) {
        printf("Enter the source node value: ");
        scanf("%d", &source);
        printf("Enter the destination node value: ");
        scanf("%d", &destination);
        addEdge(&graph, source, destination);
    }

    int visited[MAX_VERTICES] = {0};
    printf("Enter the root for BFS: ");
    scanf("%d", &root);
    printf("BFS Traversal:\n");
    bfs(root, graph, visited);

    return 0;
}
