/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 22967                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/22967                          #+#        #+#      #+#    */
/*   Solved: 2026/04/12 14:32:56 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

#define MAX_N 305

int graph[MAX_N][MAX_N], deg[MAX_N];
int adj[MAX_N][MAX_N];
int dist[MAX_N], par[MAX_N];
int queue[MAX_N];
int N;

void bfs(int src) {
    memset(dist, -1, sizeof(dist));
    int head=0, tail=0;
    dist[src]=0; par[src]=-1; queue[tail++]=src;
    while (head<tail) {
        int u=queue[head++];
        for (int i=0; i<deg[u]; i++) {
            int v=graph[u][i];
            if (dist[v]==-1) { dist[v]=dist[u]+1; par[v]=u; queue[tail++]=v; }
        }
    }
}

int newU[MAX_N], newV[MAX_N];
int nEdges;

int main() {
    scanf("%d", &N);
    for (int i=0; i<N-1; i++) {
        int u,v; scanf("%d %d",&u,&v);
        graph[u][deg[u]++]=v; graph[v][deg[v]++]=u;
        adj[u][v]=adj[v][u]=1;
    }

    int diameter;
    nEdges=0;

    if (N <= 4) {
        diameter=1;
        for (int i=1;i<=N;i++)
            for (int j=i+1;j<=N;j++)
                if (!adj[i][j]) { newU[nEdges]=i; newV[nEdges]=j; nEdges++; }
    } else {
        bfs(1);
        int u=1; for (int i=1;i<=N;i++) if (dist[i]>dist[u]) u=i;
        bfs(u);
        int v=1; for (int i=1;i<=N;i++) if (dist[i]>dist[v]) v=i;
        int D=dist[v];

        // 경로 복원
        int path[MAX_N], plen=0, cur=v;
        while (cur!=-1) { path[plen++]=cur; cur=par[cur]; }
        int center=path[D/2];

        diameter=2;
        for (int i=1;i<=N;i++)
            if (i!=center && !adj[i][center]) {
                newU[nEdges]=i; newV[nEdges]=center; nEdges++;
            }
    }

    printf("%d\n%d\n", nEdges, diameter);
    for (int i=0;i<nEdges;i++) printf("%d %d\n", newU[i], newV[i]);
    return 0;
}