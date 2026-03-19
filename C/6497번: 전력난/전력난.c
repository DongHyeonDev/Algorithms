/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 6497                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/6497                           #+#        #+#      #+#    */
/*   Solved: 2026/03/19 11:18:09 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

#define MAX_M 200001
#define MAX_N 200001

int parent[MAX_M];

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

typedef struct { int w, u, v; } Edge;
Edge edges[MAX_N];

int cmp(const void* a, const void* b) {
    return ((Edge*)a)->w - ((Edge*)b)->w;
}

int main() {
    int m, n;
    while (scanf("%d %d", &m, &n) && (m || n)) {
        for (int i = 0; i < m; i++) parent[i] = i;
        
        long long total = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
            total += edges[i].w;
        }
        
        qsort(edges, n, sizeof(Edge), cmp);
        
        long long mst = 0;
        for (int i = 0; i < n; i++)
            if (unite(edges[i].u, edges[i].v))
                mst += edges[i].w;
        
        printf("%lld\n", total - mst);
    }
    return 0;
}