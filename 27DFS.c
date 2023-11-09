#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 50

typedef struct {
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
    int numVertices, numEdges;
} Graph;

typedef struct {
    int stack[MAX_VERTICES];
    int top;
} Stack;

int isStackEmpty(Stack s) {
    return (s.top == -1);
}

void push(Stack *s, int element) {
    s->top++;
    s->stack[s->top] = element;
}

int pop(Stack *s) {
    int element = s->stack[s->top];
    s->top--;
    return element;
}

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

void dfsRecursion(int rootNode, Graph g, int visited[]) {
    visited[rootNode] = 1;
    printf("%d ", rootNode);
    for (int j = 0; j < g.numVertices; j++) {
        if (g.adjacencyMatrix[rootNode][j] == 1 && visited[j] != 1) {
            dfsRecursion(j, g, visited);
        }
    }
}

void dfsIterative(int rootNode, Graph g, int visited[]) {
    Stack s;
    s.top = -1;
    push(&s, rootNode);
    while (!isStackEmpty(s)) {
        int x = pop(&s);
        if (visited[x] != 1) {
            visited[x] = 1;
            printf("%d ", x);
            for (int i = 0; i < g.numVertices; i++) {
                if (g.adjacencyMatrix[x][i] == 1 && visited[i] != 1) {
                    push(&s, i);
                }
            }
        }
    }
}

int main() {
    Graph graph;
    int root, source, destination, choice;
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
    do {
        printf("\nChoose your operation:\n");
        printf("1. DFS Recursion\n");
        printf("2. DFS Iterative\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);
        for (int i = 0; i < graph.numVertices; i++) {
            visited[i] = 0;
        }

        switch (choice) {
            case 1:
                printf("Enter the root: ");
                scanf("%d", &root);
                printf("DFS Recursion:\n");
                dfsRecursion(root, graph, visited);
                break;
            case 2:
                printf("Enter the root: ");
                scanf("%d", &root);
                printf("DFS Iterative:\n");
                dfsIterative(root, graph, visited);
                break;
            case 3:
                exit(0);
        }
    } while (1);
    return 0;
}
