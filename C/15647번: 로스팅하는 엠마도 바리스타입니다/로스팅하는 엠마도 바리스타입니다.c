/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 15647                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/15647                          #+#        #+#      #+#    */
/*   Solved: 2026/03/27 12:49:59 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

#define MAX_N 300001
#define MAX_E 600001

int to[MAX_E], wt[MAX_E], nxt[MAX_E], head_arr[MAX_N], eCnt;
int par[MAX_N], parW[MAX_N], sz[MAX_N];
long long down_sum[MAX_N], ans[MAX_N];
int queue[MAX_N], order[MAX_N];
int visited[MAX_N];

void addEdge(int u, int v, int w) {
    to[eCnt]=v; wt[eCnt]=w; nxt[eCnt]=head_arr[u]; head_arr[u]=eCnt++;
}

int main() {
    int N; scanf("%d",&N);
    memset(head_arr,-1,sizeof(head_arr));
    
    for (int i=0;i<N-1;i++) {
        int u,v,d; scanf("%d %d %d",&u,&v,&d);
        addEdge(u,v,d); addEdge(v,u,d);
    }
    
    // BFS
    int qh=0,qt=0,oCnt=0;
    visited[1]=1; sz[1]=1; queue[qt++]=1;
    while (qh<qt) {
        int u=queue[qh++]; order[oCnt++]=u;
        for (int e=head_arr[u];e!=-1;e=nxt[e]) {
            int v=to[e],w=wt[e];
            if (!visited[v]) { visited[v]=1; sz[v]=1; par[v]=u; parW[v]=w; queue[qt++]=v; }
        }
    }
    
    // 1단계: 역순으로 down, sz
    for (int i=oCnt-1;i>=0;i--) {
        int u=order[i];
        for (int e=head_arr[u];e!=-1;e=nxt[e]) {
            int c=to[e],w=wt[e];
            if (c==par[u]) continue;
            sz[u] += sz[c];
            down_sum[u] += down_sum[c] + (long long)sz[c]*w;
        }
    }
    
    // 2단계: 루트 → 자식 ans 전파
    ans[1] = down_sum[1];
    for (int i=0;i<oCnt;i++) {
        int u=order[i];
        for (int e=head_arr[u];e!=-1;e=nxt[e]) {
            int c=to[e],w=wt[e];
            if (c==par[u]) continue;
            ans[c] = ans[u] + (long long)(N - 2*sz[c])*w;
        }
    }
    
    for (int i=1;i<=N;i++) printf("%lld\n", ans[i]);
    return 0;
}