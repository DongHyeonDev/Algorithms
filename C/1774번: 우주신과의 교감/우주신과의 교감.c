/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1774                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1774                           #+#        #+#      #+#    */
/*   Solved: 2026/03/18 14:15:24 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_N 1001
#define MAX_E 500001

int parent[MAX_N];

int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

int unite(int a, int b) {
    int ra = find(a), rb = find(b);
    if (ra == rb) return 0;
    parent[rb] = ra;
    return 1;
}

typedef struct { double w; int u, v; } Edge;
Edge edges[MAX_E];

int cmp(const void* a, const void* b) {
    double d = ((Edge*)a)->w - ((Edge*)b)->w;
    return d < 0 ? -1 : d > 0 ? 1 : 0;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    double x[MAX_N], y[MAX_N];
    for (int i = 1; i <= N; i++) scanf("%lf %lf", &x[i], &y[i]);
    
    for (int i = 1; i <= N; i++) parent[i] = i;
    
    // 기존 연결 통로 먼저 반영
    for (int i = 0; i < M; i++) {
        int a, b; scanf("%d %d", &a, &b);
        unite(a, b);
    }
    
    // 모든 쌍의 거리 간선 생성
    int eCnt = 0;
    for (int i = 1; i <= N; i++)
        for (int j = i+1; j <= N; j++) {
            double dx = x[i]-x[j], dy = y[i]-y[j];
            edges[eCnt++] = (Edge){sqrt(dx*dx + dy*dy), i, j};
        }
    
    qsort(edges, eCnt, sizeof(Edge), cmp);
    
    double total = 0.0;
    for (int i = 0; i < eCnt; i++)
        if (unite(edges[i].u, edges[i].v))
            total += edges[i].w;
    
    printf("%.2f\n", total);
    return 0;
}