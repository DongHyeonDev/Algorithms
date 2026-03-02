/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11779                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11779                          #+#        #+#      #+#    */
/*   Solved: 2026/03/02 21:15:12 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

#define MAX_N 1001
#define MAX_M 100001
#define INF 1000000000

// 인접 리스트 (정적 배열)
int to[MAX_M], wt[MAX_M], nxt[MAX_M], head[MAX_N];
int edge_cnt = 0;

void addEdge(int u, int v, int w) {
    to[edge_cnt] = v;
    wt[edge_cnt] = w;
    nxt[edge_cnt] = head[u];
    head[u] = edge_cnt++;
}

int dist[MAX_N], from[MAX_N];
int visited[MAX_N];
int path[MAX_N];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    memset(head, -1, sizeof(head));
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }
    
    int A, B;
    scanf("%d %d", &A, &B);
    
    for (int i = 1; i <= n; i++) { dist[i] = INF; from[i] = -1; }
    dist[A] = 0;
    
    for (int iter = 0; iter < n; iter++) {
        // 미방문 중 최소 dist 선택
        int u = -1;
        for (int v = 1; v <= n; v++)
            if (!visited[v] && (u == -1 || dist[v] < dist[u])) u = v;
        if (u == -1 || dist[u] == INF) break;
        visited[u] = 1;
        
        for (int e = head[u]; e != -1; e = nxt[e]) {
            int v = to[e], w = wt[e];
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                from[v] = u;
            }
        }
    }
    
    printf("%d\n", dist[B]);
    
    // 역추적
    int len = 0, cur = B;
    while (cur != -1) { path[len++] = cur; cur = from[cur]; }
    
    printf("%d\n", len);
    for (int i = len - 1; i >= 0; i--) {
        printf("%d", path[i]);
        if (i > 0) printf(" ");
    }
    printf("\n");
    
    return 0;
}