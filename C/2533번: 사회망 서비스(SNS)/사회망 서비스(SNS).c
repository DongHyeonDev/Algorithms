/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2533                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2533                           #+#        #+#      #+#    */
/*   Solved: 2026/03/23 12:55:14 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

#define MAX_N 1000001
#define MAX_E 2000001

int to[MAX_E], nxt[MAX_E], head_arr[MAX_N], eCnt;
int par[MAX_N], dp[MAX_N][2];
int queue[MAX_N], order[MAX_N];
int visited[MAX_N];

void addEdge(int u, int v) {
    to[eCnt]=v; nxt[eCnt]=head_arr[u]; head_arr[u]=eCnt++;
}

int min2(int a, int b) { return a<b?a:b; }

int main() {
    int N; scanf("%d",&N);
    
    memset(head_arr,-1,sizeof(head_arr));
    for (int i=0;i<N-1;i++) {
        int u,v; scanf("%d %d",&u,&v);
        addEdge(u,v); addEdge(v,u);
    }
    
    // BFS
    int qh=0,qt=0,oCnt=0;
    visited[1]=1; queue[qt++]=1;
    while (qh<qt) {
        int u=queue[qh++]; order[oCnt++]=u;
        for (int e=head_arr[u];e!=-1;e=nxt[e]) {
            int v=to[e];
            if (!visited[v]) { visited[v]=1; par[v]=u; queue[qt++]=v; }
        }
    }
    
    // 역순 DP
    for (int i=oCnt-1;i>=0;i--) {
        int u=order[i];
        dp[u][1]=1; dp[u][0]=0;
        for (int e=head_arr[u];e!=-1;e=nxt[e]) {
            int c=to[e];
            if (c==par[u]) continue;
            dp[u][1] += min2(dp[c][0], dp[c][1]);
            dp[u][0] += dp[c][1];
        }
    }
    
    printf("%d\n", min2(dp[1][0], dp[1][1]));
    return 0;
}