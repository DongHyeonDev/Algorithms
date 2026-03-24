/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2213                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2213                           #+#        #+#      #+#    */
/*   Solved: 2026/03/24 03:49:29 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

#define MAX_N 10001
#define MAX_E 20001

int to[MAX_E], nxt[MAX_E], head_arr[MAX_N], eCnt;
int w[MAX_N], par[MAX_N];
int dp[MAX_N][2];
int queue[MAX_N], order[MAX_N], visited[MAX_N];
int stateArr[MAX_N], selected[MAX_N];

void addEdge(int u, int v) {
    to[eCnt]=v; nxt[eCnt]=head_arr[u]; head_arr[u]=eCnt++;
}

int max2(int a, int b) { return a>b?a:b; }

int main() {
    int N; scanf("%d",&N);
    for (int i=1;i<=N;i++) scanf("%d",&w[i]);
    
    memset(head_arr,-1,sizeof(head_arr));
    int u,v;
    while (scanf("%d %d",&u,&v)==2) { addEdge(u,v); addEdge(v,u); }
    
    // BFS
    int qh=0,qt=0,oCnt=0;
    visited[1]=1; queue[qt++]=1;
    while (qh<qt) {
        u=queue[qh++]; order[oCnt++]=u;
        for (int e=head_arr[u];e!=-1;e=nxt[e]) {
            v=to[e];
            if (!visited[v]) { visited[v]=1; par[v]=u; queue[qt++]=v; }
        }
    }
    
    // 역순 DP
    for (int i=oCnt-1;i>=0;i--) {
        u=order[i]; dp[u][1]=w[u]; dp[u][0]=0;
        for (int e=head_arr[u];e!=-1;e=nxt[e]) {
            int c=to[e]; if (c==par[u]) continue;
            dp[u][1] += dp[c][0];
            dp[u][0] += max2(dp[c][0],dp[c][1]);
        }
    }
    
    printf("%d\n", max2(dp[1][0],dp[1][1]));
    
    // 역추적
    stateArr[1] = dp[1][1]>=dp[1][0] ? 1 : 0;
    if (stateArr[1]) selected[1]=1;
    
    for (int i=0;i<oCnt;i++) {
        u=order[i];
        for (int e=head_arr[u];e!=-1;e=nxt[e]) {
            int c=to[e]; if (c==par[u]) continue;
            stateArr[c] = (stateArr[u]==1) ? 0 : (dp[c][1]>=dp[c][0] ? 1 : 0);
            if (stateArr[c]) selected[c]=1;
        }
    }
    
    int first=1;
    for (int i=1;i<=N;i++) if (selected[i]) {
        if (!first) printf(" ");
        printf("%d",i); first=0;
    }
    printf("\n");
    return 0;
}