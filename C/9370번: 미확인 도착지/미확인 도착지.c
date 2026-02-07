/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9370                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9370                           #+#        #+#      #+#    */
/*   Solved: 2026/02/07 16:00:06 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INF 2000000000
#define MAX_N 2001
#define MAX_M 50001

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

Node* adj[MAX_N];
int dist[MAX_N];
int gh_dist;

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

void dijkstra(int start, int n, int result[]) {
    PriorityQueue* pq = create_pq(MAX_M);
    
    for (int i = 1; i <= n; i++) {
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

void free_graph(int n) {
    for (int i = 1; i <= n; i++) {
        Node* node = adj[i];
        while (node != NULL) {
            Node* temp = node;
            node = node->next;
            free(temp);
        }
        adj[i] = NULL;
    }
}

int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int main() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        int n, m, t;
        scanf("%d %d %d", &n, &m, &t);
        
        int s, g, h;
        scanf("%d %d %d", &s, &g, &h);
        
        memset(adj, 0, sizeof(adj));
        gh_dist = 0;
        
        for (int i = 0; i < m; i++) {
            int a, b, d;
            scanf("%d %d %d", &a, &b, &d);
            add_edge(a, b, d);
            add_edge(b, a, d);
            
            if ((a == g && b == h) || (a == h && b == g)) {
                gh_dist = d;
            }
        }
        
        int targets[100];
        for (int i = 0; i < t; i++) {
            scanf("%d", &targets[i]);
        }
        
        // s, g, h에서 다익스트라
        int distS[MAX_N], distG[MAX_N], distH[MAX_N];
        dijkstra(s, n, distS);
        dijkstra(g, n, distG);
        dijkstra(h, n, distH);
        
        int result[100];
        int result_cnt = 0;
        
        for (int i = 0; i < t; i++) {
            int dest = targets[i];
            int shortest = distS[dest];
            
            // s -> g -> h -> dest 또는 s -> h -> g -> dest
            int path1 = distS[g] + gh_dist + distH[dest];
            int path2 = distS[h] + gh_dist + distG[dest];
            
            if (shortest == path1 || shortest == path2) {
                result[result_cnt++] = dest;
            }
        }
        
        qsort(result, result_cnt, sizeof(int), compare);
        
        for (int i = 0; i < result_cnt; i++) {
            if (i > 0) printf(" ");
            printf("%d", result[i]);
        }
        printf("\n");
        
        free_graph(n);
    }
    
    return 0;
}