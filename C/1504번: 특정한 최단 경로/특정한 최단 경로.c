/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1504                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1504                           #+#        #+#      #+#    */
/*   Solved: 2026/02/05 12:45:18 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INF 200000000

typedef struct Node {
    int vertex;
    int weight;
    struct Node* next;
} Node;

typedef struct {
    int vertex;
    int dist;
} Element;

typedef struct {
    Element* heap;
    int size;
    int capacity;
} PriorityQueue;

Node* adj[801];
int dist[801];

void add_edge(int u, int v, int w) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->vertex = v;
    node->weight = w;
    node->next = adj[u];
    adj[u] = node;
}

PriorityQueue* create_pq(int capacity) {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->heap = (Element*)malloc(sizeof(Element) * (capacity + 1));
    pq->size = 0;
    pq->capacity = capacity;
    return pq;
}

void push(PriorityQueue* pq, int vertex, int dist) {
    pq->heap[++pq->size].vertex = vertex;
    pq->heap[pq->size].dist = dist;
    int idx = pq->size;
    
    while (idx > 1 && pq->heap[idx].dist < pq->heap[idx / 2].dist) {
        Element temp = pq->heap[idx];
        pq->heap[idx] = pq->heap[idx / 2];
        pq->heap[idx / 2] = temp;
        idx /= 2;
    }
}

Element pop(PriorityQueue* pq) {
    Element result = pq->heap[1];
    pq->heap[1] = pq->heap[pq->size--];
    
    int idx = 1;
    while (idx * 2 <= pq->size) {
        int child = idx * 2;
        if (child + 1 <= pq->size && pq->heap[child + 1].dist < pq->heap[child].dist) {
            child++;
        }
        if (pq->heap[idx].dist <= pq->heap[child].dist) break;
        
        Element temp = pq->heap[idx];
        pq->heap[idx] = pq->heap[child];
        pq->heap[child] = temp;
        idx = child;
    }
    
    return result;
}

int is_empty(PriorityQueue* pq) {
    return pq->size == 0;
}

void dijkstra(int start, int N, int result[]) {
    PriorityQueue* pq = create_pq(200001);
    
    for (int i = 1; i <= N; i++) {
        result[i] = INF;
    }
    result[start] = 0;
    push(pq, start, 0);
    
    while (!is_empty(pq)) {
        Element cur = pop(pq);
        int u = cur.vertex;
        int d = cur.dist;
        
        if (d > result[u]) continue;
        
        for (Node* node = adj[u]; node != NULL; node = node->next) {
            int v = node->vertex;
            int w = node->weight;
            
            if (result[u] + w < result[v]) {
                result[v] = result[u] + w;
                push(pq, v, result[v]);
            }
        }
    }
    
    free(pq->heap);
    free(pq);
}

int min(int a, int b) {
    return a < b ? a : b;
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
    int N, E;
    scanf("%d %d", &N, &E);
    
    memset(adj, 0, sizeof(adj));
    
    for (int i = 0; i < E; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        add_edge(a, b, c);
        add_edge(b, a, c);
    }
    
    int v1, v2;
    scanf("%d %d", &v1, &v2);
    
    // 1, v1, v2에서 각각 다익스트라 수행
    int dist1[801], distV1[801], distV2[801];
    dijkstra(1, N, dist1);
    dijkstra(v1, N, distV1);
    dijkstra(v2, N, distV2);
    
    // 경로1: 1 -> v1 -> v2 -> N
    // 경로2: 1 -> v2 -> v1 -> N
    int path1 = dist1[v1] + distV1[v2] + distV2[N];
    int path2 = dist1[v2] + distV2[v1] + distV1[N];
    
    int answer = min(path1, path2);
    
    if (answer >= INF) {
        printf("-1\n");
    } else {
        printf("%d\n", answer);
    }
    
    free_graph(N);
    
    return 0;
}