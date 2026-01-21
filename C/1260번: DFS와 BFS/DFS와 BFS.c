/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1260                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1260                           #+#        #+#      #+#    */
/*   Solved: 2026/01/21 11:17:47 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int* data;
    int size;
    int capacity;
} Vector;

typedef struct {
    int data[1001];
    int front;
    int rear;
} Queue;

Vector graph[1001];
int visited[1001];

void init_vector(Vector* v) {
    v->capacity = 4;
    v->size = 0;
    v->data = (int*)malloc(v->capacity * sizeof(int));
}

void push_back(Vector* v, int value) {
    if (v->size >= v->capacity) {
        v->capacity *= 2;
        v->data = (int*)realloc(v->data, v->capacity * sizeof(int));
    }
    v->data[v->size++] = value;
}

int compare_asc(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

void init_queue(Queue* q) {
    q->front = 0;
    q->rear = 0;
}

void enqueue(Queue* q, int value) {
    q->data[q->rear++] = value;
}

int dequeue(Queue* q) {
    return q->data[q->front++];
}

int is_empty(Queue* q) {
    return q->front == q->rear;
}

void dfs(int node) {
    visited[node] = 1;
    printf("%d ", node);
    
    for (int i = 0; i < graph[node].size; i++) {
        int next = graph[node].data[i];
        if (!visited[next]) {
            dfs(next);
        }
    }
}

void bfs(int start) {
    Queue q;
    init_queue(&q);
    
    enqueue(&q, start);
    visited[start] = 1;
    
    while (!is_empty(&q)) {
        int node = dequeue(&q);
        printf("%d ", node);
        
        for (int i = 0; i < graph[node].size; i++) {
            int next = graph[node].data[i];
            if (!visited[next]) {
                visited[next] = 1;
                enqueue(&q, next);
            }
        }
    }
}

int main() {
    int N, M, V;
    scanf("%d %d %d", &N, &M, &V);
    
    // 벡터 초기화
    for (int i = 1; i <= N; i++) {
        init_vector(&graph[i]);
    }
    
    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        push_back(&graph[u], v);
        push_back(&graph[v], u);
    }
    
    // 각 정점의 인접 리스트를 오름차순 정렬
    for (int i = 1; i <= N; i++) {
        qsort(graph[i].data, graph[i].size, sizeof(int), compare_asc);
    }
    
    // DFS
    dfs(V);
    printf("\n");
    
    // visited 배열 초기화
    memset(visited, 0, sizeof(visited));
    
    // BFS
    bfs(V);
    printf("\n");
    
    // 메모리 해제
    for (int i = 1; i <= N; i++) {
        free(graph[i].data);
    }
    
    return 0;
}