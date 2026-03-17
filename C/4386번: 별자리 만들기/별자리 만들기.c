/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 4386                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/4386                           #+#        #+#      #+#    */
/*   Solved: 2026/03/17 12:19:48 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_N 101
#define MAX_E 5001

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
    double diff = ((Edge*)a)->w - ((Edge*)b)->w;
    return diff < 0 ? -1 : diff > 0 ? 1 : 0;
}

int main() {
    int n;
    scanf("%d", &n);
    
    double x[MAX_N], y[MAX_N];
    for (int i = 0; i < n; i++) scanf("%lf %lf", &x[i], &y[i]);
    
    // 모든 쌍의 거리를 간선으로 생성
    int eCnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++) {
            double dx = x[i]-x[j], dy = y[i]-y[j];
            edges[eCnt++] = (Edge){sqrt(dx*dx + dy*dy), i, j};
        }
    
    qsort(edges, eCnt, sizeof(Edge), cmp);
    for (int i = 0; i < n; i++) parent[i] = i;
    
    double total = 0.0;
    int count = 0;
    for (int i = 0; i < eCnt && count < n-1; i++) {
        if (unite(edges[i].u, edges[i].v)) {
            total += edges[i].w;
            count++;
        }
    }
    
    printf("%.2f\n", total);
    return 0;
}