/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1707                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1707                           #+#        #+#      #+#    */
/*   Solved: 2026/01/31 10:54:54 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adj[20001];
int color[20001];
int queue[20001];
int front, rear;

void add_edge(int u, int v) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->vertex = v;
    node->next = adj[u];
    adj[u] = node;
}

int bfs(int start) {
    front = 0;
    rear = 0;
    
    queue[rear++] = start;
    color[start] = 1;
    
    while (front < rear) {
        int cur = queue[front++];
        
        for (Node* node = adj[cur]; node != NULL; node = node->next) {
            int next = node->vertex;
            
            if (color[next] == 0) {
                color[next] = 3 - color[cur];  // 1 -> 2, 2 -> 1
                queue[rear++] = next;
            } else if (color[next] == color[cur]) {
                return 0;  // 같은 색이면 이분 그래프 아님
            }
        }
    }
    
    return 1;
}

int is_bipartite(int V) {
    memset(color, 0, sizeof(color));
    
    // 모든 정점에 대해 확인 (연결되지 않은 그래프 고려)
    for (int i = 1; i <= V; i++) {
        if (color[i] == 0) {
            if (!bfs(i)) {
                return 0;
            }
        }
    }
    
    return 1;
}

void free_graph(int V) {
    for (int i = 1; i <= V; i++) {
        Node* node = adj[i];
        while (node != NULL) {
            Node* temp = node;
            node = node->next;
            free(temp);
        }
        adj[i] = NULL;
    }
}

int main() {
    int K;
    scanf("%d", &K);
    
    while (K--) {
        int V, E;
        scanf("%d %d", &V, &E);
        
        memset(adj, 0, sizeof(adj));
        
        for (int i = 0; i < E; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            add_edge(u, v);
            add_edge(v, u);
        }
        
        if (is_bipartite(V)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
        
        free_graph(V);
    }
    
    return 0;
}