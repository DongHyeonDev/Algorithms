/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2533                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2533                           #+#        #+#      #+#    */
/*   Solved: 2026/03/23 12:55:20 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int N; cin >> N;
    vector<vector<int>> graph(N+1);
    for (int i=0;i<N-1;i++) {
        int u,v; cin>>u>>v;
        graph[u].push_back(v); graph[v].push_back(u);
    }
    
    vector<int> par(N+1,0), order;
    vector<array<int,2>> dp(N+1, {0,0});
    vector<bool> visited(N+1,false);
    order.reserve(N);
    
    // BFS로 방문 순서 + 부모 설정
    queue<int> q;
    q.push(1); visited[1]=true;
    while (!q.empty()) {
        int u=q.front(); q.pop(); order.push_back(u);
        for (int v:graph[u]) if (!visited[v]) {
            visited[v]=true; par[v]=u; q.push(v);
        }
    }
    
    // 역순 DP (리프 → 루트)
    for (int i=(int)order.size()-1;i>=0;i--) {
        int u=order[i];
        dp[u][1]=1; dp[u][0]=0;
        for (int c:graph[u]) {
            if (c==par[u]) continue;
            dp[u][1] += min(dp[c][0], dp[c][1]); // 자식은 자유
            dp[u][0] += dp[c][1];                 // 자식은 반드시 얼리 어답터
        }
    }
    
    cout << min(dp[1][0], dp[1][1]) << "\n";
    return 0;
}