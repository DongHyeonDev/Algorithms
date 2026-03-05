/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1167                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1167                           #+#        #+#      #+#    */
/*   Solved: 2026/03/05 16:23:12 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

#define MAX_V  100001
#define MAX_E  200001

int to[MAX_E], wt[MAX_E], nxt[MAX_E], head_arr[MAX_V];
int edge_cnt = 0;

void addEdge(int u, int v, int w) {
    to[edge_cnt] = v; wt[edge_cnt] = w;
    nxt[edge_cnt] = head_arr[u];
    head_arr[u] = edge_cnt++;
}

int dist[MAX_V];
int queue[MAX_V];

// BFS: src에서 최장 거리 노드 반환
int bfs(int src, int V) {
    memset(dist, -1, sizeof(int) * (V + 1));
    int qHead = 0, qTail = 0;
    dist[src] = 0;
    queue[qTail++] = src;
    
    while (qHead < qTail) {
        int u = queue[qHead++];
        for (int e = head_arr[u]; e != -1; e = nxt[e]) {
            int v = to[e], w = wt[e];
            if (dist[v] != -1) continue;
            dist[v] = dist[u] + w;
            queue[qTail++] = v;
        }
    }
    
    int far = src;
    for (int i = 1; i <= V; i++)
        if (dist[i] > dist[far]) far = i;
    return far;
}

int main() {
    int V;
    scanf("%d", &V);
    
    memset(head_arr, -1, sizeof(head_arr));
    
    for (int i = 0; i < V; i++) {
        int u, v, w;
        scanf("%d", &u);
        while (scanf("%d", &v) && v != -1) {
            scanf("%d", &w);
            addEdge(u, v, w);
            addEdge(v, u, w);
        }
    }
    
    int u = bfs(1, V);       // 1에서 가장 먼 노드 u
    bfs(u, V);               // u에서 BFS → dist에 최장 거리
    
    int ans = 0;
    for (int i = 1; i <= V; i++)
        if (dist[i] > ans) ans = dist[i];
    
    printf("%d\n", ans);
    return 0;
}