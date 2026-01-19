/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 24445                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/24445                          #+#        #+#      #+#    */
/*   Solved: 2026/01/19 14:54:01 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int size;
    int capacity;
} Vector;

typedef struct {
    int data[100001];
    int front;
    int rear;
} Queue;

Vector graph[100001];
int visited[100001];
int order_count = 1;

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

// 내림차순 비교 함수
int compare_desc(const void* a, const void* b) {
    return *(int*)b - *(int*)a;
}

void bfs(int start) {
    Queue q;
    init_queue(&q);
    
    enqueue(&q, start);
    visited[start] = order_count++;
    
    while (!is_empty(&q)) {
        int node = dequeue(&q);
        
        for (int i = 0; i < graph[node].size; i++) {
            int next = graph[node].data[i];
            if (visited[next] == 0) {
                visited[next] = order_count++;
                enqueue(&q, next);
            }
        }
    }
}

int main() {
    int N, M, R;
    scanf("%d %d %d", &N, &M, &R);
    
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
    
    // 각 정점의 인접 리스트를 내림차순 정렬
    for (int i = 1; i <= N; i++) {
        qsort(graph[i].data, graph[i].size, sizeof(int), compare_desc);
    }
    
    // BFS 시작
    bfs(R);
    
    // 결과 출력
    for (int i = 1; i <= N; i++) {
        printf("%d\n", visited[i]);
    }
    
    // 메모리 해제
    for (int i = 1; i <= N; i++) {
        free(graph[i].data);
    }
    
    return 0;
}