/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1197                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1197                           #+#        #+#      #+#    */
/*   Solved: 2026/03/16 13:35:27 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

#define MAX_E 100001
#define MAX_V 10001

int parent[MAX_V], rnk[MAX_V];

int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

int unite(int a, int b) {
    int ra = find(a), rb = find(b);
    if (ra == rb) return 0;
    if (rnk[ra] < rnk[rb])      parent[ra] = rb;
    else if (rnk[ra] > rnk[rb]) parent[rb] = ra;
    else { parent[rb] = ra; rnk[ra]++; }
    return 1;
}

typedef struct { int w, u, v; } Edge;
Edge edges[MAX_E];

int cmp(const void* a, const void* b) {
    return ((Edge*)a)->w - ((Edge*)b)->w;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);
    
    for (int i = 0; i < E; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    
    qsort(edges, E, sizeof(Edge), cmp);
    
    for (int i = 1; i <= V; i++) parent[i] = i;
    
    long long total = 0;
    int count = 0;
    for (int i = 0; i < E && count < V - 1; i++) {
        if (unite(edges[i].u, edges[i].v)) {
            total += edges[i].w;
            count++;
        }
    }
    
    printf("%lld\n", total);
    return 0;
}