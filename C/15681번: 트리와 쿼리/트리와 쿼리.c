/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 15681                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/15681                          #+#        #+#      #+#    */
/*   Solved: 2026/03/21 17:06:11 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

#define MAX_N 100001
#define MAX_E 200001

int to[MAX_E], nxt[MAX_E], head_arr[MAX_N];
int edge_cnt = 0;

void addEdge(int u, int v) {
    to[edge_cnt] = v;
    nxt[edge_cnt] = head_arr[u];
    head_arr[u] = edge_cnt++;
}

int par[MAX_N], sz[MAX_N];
int queue[MAX_N], order[MAX_N];
int visited[MAX_N];

int main() {
    int N, R, Q;
    scanf("%d %d %d", &N, &R, &Q);
    
    memset(head_arr, -1, sizeof(head_arr));
    for (int i = 0; i < N - 1; i++) {
        int u, v; scanf("%d %d", &u, &v);
        addEdge(u, v); addEdge(v, u);
    }
    
    // BFS로 방문 순서 기록
    int head = 0, tail = 0, oCnt = 0;
    visited[R] = 1; par[R] = 0;
    queue[tail++] = R;
    
    while (head < tail) {
        int u = queue[head++];
        order[oCnt++] = u;
        for (int e = head_arr[u]; e != -1; e = nxt[e]) {
            int v = to[e];
            if (visited[v]) continue;
            visited[v] = 1;
            par[v] = u;
            queue[tail++] = v;
        }
    }
    
    // 모든 노드의 초기 크기 = 1
    for (int i = 1; i <= N; i++) sz[i] = 1;
    
    // 역순으로 size 누적
    for (int i = oCnt - 1; i >= 0; i--) {
        int u = order[i];
        if (par[u]) sz[par[u]] += sz[u];
    }
    
    for (int i = 0; i < Q; i++) {
        int u; scanf("%d", &u);
        printf("%d\n", sz[u]);
    }
    return 0;
}