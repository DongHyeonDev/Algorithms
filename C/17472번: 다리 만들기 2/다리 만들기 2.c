/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 17472                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/17472                          #+#        #+#      #+#    */
/*   Solved: 2026/03/20 15:33:53 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_RC 10
#define MAX_E  10000

int grid[MAX_RC][MAX_RC], island[MAX_RC][MAX_RC];
int N, M, islandCnt;
int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};

// BFS용 큐
int qr[MAX_RC*MAX_RC], qc[MAX_RC*MAX_RC];

void bfs(int si, int sj, int id) {
    int head = 0, tail = 0;
    island[si][sj] = id;
    qr[tail] = si; qc[tail++] = sj;
    while (head < tail) {
        int r = qr[head], c = qc[head++];
        for (int d = 0; d < 4; d++) {
            int nr = r+dx[d], nc = c+dy[d];
            if (nr<0||nr>=N||nc<0||nc>=M) continue;
            if (grid[nr][nc]==1 && island[nr][nc]==0) {
                island[nr][nc] = id;
                qr[tail] = nr; qc[tail++] = nc;
            }
        }
    }
}

typedef struct { int w, u, v; } Edge;
Edge edges[MAX_E];
int eCnt;

int cmp(const void* a, const void* b) { return ((Edge*)a)->w - ((Edge*)b)->w; }

int parent[7];
int find(int x) { return parent[x]==x ? x : (parent[x]=find(parent[x])); }
int unite(int a, int b) {
    int ra=find(a), rb=find(b);
    if (ra==rb) return 0;
    parent[rb]=ra; return 1;
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++) scanf("%d",&grid[i][j]);
    
    // 1단계: 섬 번호
    islandCnt = 0;
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            if (grid[i][j]==1 && island[i][j]==0)
                bfs(i, j, ++islandCnt);
    
    // 2단계: 다리 탐색
    eCnt = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (!grid[i][j]) continue;
            int src = island[i][j];
            for (int d=0; d<4; d++) {
                int r=i+dx[d], c=j+dy[d], len=0;
                while (r>=0&&r<N&&c>=0&&c<M&&grid[r][c]==0) {
                    len++; r+=dx[d]; c+=dy[d];
                }
                if (r>=0&&r<N&&c>=0&&c<M&&grid[r][c]==1
                    &&island[r][c]!=src&&len>=2)
                    edges[eCnt++] = (Edge){len, src, island[r][c]};
            }
        }
    }
    
    // 3단계: MST
    qsort(edges, eCnt, sizeof(Edge), cmp);
    for (int i=1; i<=islandCnt; i++) parent[i]=i;
    
    int total=0, cnt=0;
    for (int i=0; i<eCnt&&cnt<islandCnt-1; i++)
        if (unite(edges[i].u, edges[i].v)) { total+=edges[i].w; cnt++; }
    
    printf("%d\n", cnt==islandCnt-1 ? total : -1);
    return 0;
}