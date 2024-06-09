#include <stdio.h>

#define UNDISCOVERED 0
#define DISCOVERED 1
#define PROCESSED 2

#define MAX_VERTICES 100

int state[MAX_VERTICES];
int discovery[MAX_VERTICES];
int finish[MAX_VERTICES];
int parent[MAX_VERTICES];
int t = 0; // 글로벌 타임스탬프 변수

// 인접 리스트 구조 정의
struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
};

struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(struct Node*));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

void DFS(struct Graph* graph, int s) {
    state[s] = DISCOVERED;
    t = t + 1;
    discovery[s] = t; // 발견 시간

    struct Node* adjList = graph->adjLists[s];
    struct Node* temp = adjList;

    while (temp != NULL) {
        int v = temp->vertex;
        if (state[v] == UNDISCOVERED) {
            parent[v] = s;
            DFS(graph, v);
        }
        temp = temp->next;
    }

    state[s] = PROCESSED;
    t = t + 1;
    finish[s] = t; // 완료 시간
}

int main() {
    int vertices = 6;
    struct Graph* graph = createGraph(vertices);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 5);

    for (int i = 0; i < vertices; i++) {
        state[i] = UNDISCOVERED;
        parent[i] = -1;
    }

    for (int i = 0; i < vertices; i++) {
        if (state[i] == UNDISCOVERED) {
            DFS(graph, i);
        }
    }

    printf("Vertex  Discovery  Finish\n");
    for (int i = 0; i < vertices; i++) {
        printf("%d\t\t%d\t\t%d\n", i, discovery[i], finish[i]);
    }

    return 0;
}
