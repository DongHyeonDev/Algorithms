/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11725                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11725                          #+#        #+#      #+#    */
/*   Solved: 2026/03/04 13:04:39 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

#define MAX_N 100001
#define MAX_E 200001  // 양방향이므로 간선 2배

// 인접 리스트 (정적 배열)
int to[MAX_E], nxt[MAX_E], head[MAX_N];
int edge_cnt = 0;

void addEdge(int u, int v) {
    to[edge_cnt] = v;
    nxt[edge_cnt] = head[u];
    head[u] = edge_cnt++;
}

int parent[MAX_N];
int visited[MAX_N];
int queue[MAX_N];

int main() {
    int N;
    scanf("%d", &N);
    
    memset(head, -1, sizeof(head));
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }
    
    // BFS
    int qHead = 0, qTail = 0;
    visited[1] = 1;
    queue[qTail++] = 1;
    
    while (qHead < qTail) {
        int u = queue[qHead++];
        for (int e = head[u]; e != -1; e = nxt[e]) {
            int v = to[e];
            if (visited[v]) continue;
            visited[v] = 1;
            parent[v] = u;
            queue[qTail++] = v;
        }
    }
    
    for (int i = 2; i <= N; i++) printf("%d\n", parent[i]);
    return 0;
}