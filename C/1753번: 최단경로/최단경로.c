/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1753                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1753                           #+#        #+#      #+#    */
/*   Solved: 2026/02/04 12:25:15 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INF 987654321

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

Node* adj[20001];
int dist[20001];

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

void dijkstra(int start, int V) {
    PriorityQueue* pq = create_pq(300001);
    
    for (int i = 1; i <= V; i++) {
        dist[i] = INF;
    }
    dist[start] = 0;
    push(pq, start, 0);
    
    while (!is_empty(pq)) {
        Element cur = pop(pq);
        int u = cur.vertex;
        int d = cur.dist;
        
        if (d > dist[u]) continue;
        
        for (Node* node = adj[u]; node != NULL; node = node->next) {
            int v = node->vertex;
            int w = node->weight;
            
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(pq, v, dist[v]);
            }
        }
    }
    
    free(pq->heap);
    free(pq);
}

void free_graph(int V) {
    for (int i = 1; i <= V; i++) {
        Node* node = adj[i];
        while (node != NULL) {
            Node* temp = node;
            node = node->next;
            free(temp);
        }
    }
}

int main() {
    int V, E, K;
    scanf("%d %d", &V, &E);
    scanf("%d", &K);
    
    memset(adj, 0, sizeof(adj));
    
    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        add_edge(u, v, w);
    }
    
    dijkstra(K, V);
    
    for (int i = 1; i <= V; i++) {
        if (dist[i] == INF) {
            printf("INF\n");
        } else {
            printf("%d\n", dist[i]);
        }
    }
    
    free_graph(V);
    
    return 0;
}