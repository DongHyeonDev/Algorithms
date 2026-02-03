/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1766                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1766                           #+#        #+#      #+#    */
/*   Solved: 2026/02/03 12:21:25 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct {
    int* heap;
    int size;
    int capacity;
} PriorityQueue;

Node* adj[32001];
int indegree[32001];
int result[32001];

void add_edge(int u, int v) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->vertex = v;
    node->next = adj[u];
    adj[u] = node;
}

PriorityQueue* create_pq(int capacity) {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->heap = (int*)malloc(sizeof(int) * (capacity + 1));
    pq->size = 0;
    pq->capacity = capacity;
    return pq;
}

void push(PriorityQueue* pq, int value) {
    pq->heap[++pq->size] = value;
    int idx = pq->size;
    
    while (idx > 1 && pq->heap[idx] < pq->heap[idx / 2]) {
        int temp = pq->heap[idx];
        pq->heap[idx] = pq->heap[idx / 2];
        pq->heap[idx / 2] = temp;
        idx /= 2;
    }
}

int pop(PriorityQueue* pq) {
    int result = pq->heap[1];
    pq->heap[1] = pq->heap[pq->size--];
    
    int idx = 1;
    while (idx * 2 <= pq->size) {
        int child = idx * 2;
        if (child + 1 <= pq->size && pq->heap[child + 1] < pq->heap[child]) {
            child++;
        }
        if (pq->heap[idx] <= pq->heap[child]) break;
        
        int temp = pq->heap[idx];
        pq->heap[idx] = pq->heap[child];
        pq->heap[child] = temp;
        idx = child;
    }
    
    return result;
}

int is_empty(PriorityQueue* pq) {
    return pq->size == 0;
}

void topology_sort(int N) {
    PriorityQueue* pq = create_pq(N);
    int idx = 0;
    
    // 진입 차수가 0인 정점을 우선순위 큐에 넣기
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            push(pq, i);
        }
    }
    
    while (!is_empty(pq)) {
        int cur = pop(pq);
        result[idx++] = cur;
        
        // 현재 정점과 연결된 정점들의 진입 차수 감소
        for (Node* node = adj[cur]; node != NULL; node = node->next) {
            int next = node->vertex;
            indegree[next]--;
            
            if (indegree[next] == 0) {
                push(pq, next);
            }
        }
    }
    
    // 결과 출력
    for (int i = 0; i < N; i++) {
        if (i > 0) printf(" ");
        printf("%d", result[i]);
    }
    printf("\n");
    
    free(pq->heap);
    free(pq);
}

void free_graph(int N) {
    for (int i = 1; i <= N; i++) {
        Node* node = adj[i];
        while (node != NULL) {
            Node* temp = node;
            node = node->next;
            free(temp);
        }
    }
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    memset(adj, 0, sizeof(adj));
    memset(indegree, 0, sizeof(indegree));
    
    for (int i = 0; i < M; i++) {
        int A, B;
        scanf("%d %d", &A, &B);
        add_edge(A, B);
        indegree[B]++;
    }
    
    topology_sort(N);
    
    free_graph(N);
    
    return 0;
}