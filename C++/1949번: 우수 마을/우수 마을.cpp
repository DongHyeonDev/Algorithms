/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1949                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1949                           #+#        #+#      #+#    */
/*   Solved: 2026/03/22 03:02:02 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> w(N+1);
    for (int i=1;i<=N;i++) cin >> w[i];
    
    vector<vector<int>> graph(N+1);
    for (int i=0;i<N-1;i++) {
        int u,v; cin>>u>>v;
        graph[u].push_back(v); graph[v].push_back(u);
    }
    
    vector<int> par(N+1,0), order;
    vector<array<int,3>> dp(N+1, {0,0,0});
    vector<bool> visited(N+1,false);
    
    // BFS로 순서 + 부모 설정
    queue<int> q;
    q.push(1); visited[1]=true;
    while (!q.empty()) {
        int u=q.front(); q.pop(); order.push_back(u);
        for (int v:graph[u]) if (!visited[v]) {
            visited[v]=true; par[v]=u; q.push(v);
        }
    }
    
    const int NEG_INF = -1e9;
    
    // 역순 DP (리프 → 루트)
    for (int i=(int)order.size()-1;i>=0;i--) {
        int u=order[i];
        dp[u] = {0, w[u], 0};
        bool hasSelected = false;
        int minDiff = INT_MAX;
        
        for (int c:graph[u]) {
            if (c==par[u]) continue;
            
            // dp[u][1]: 자식 선정 불가 → dp[c][0] or dp[c][2]
            dp[u][1] += max(dp[c][0], dp[c][2]);
            
            // dp[u][0], dp[u][2]: 자식 자력 커버 → dp[c][0] or dp[c][1]
            int best = max(dp[c][0], dp[c][1]);
            dp[u][0] += best;
            dp[u][2] += best;
            
            if (dp[c][1] >= dp[c][0]) hasSelected = true;
            else minDiff = min(minDiff, dp[c][0] - dp[c][1]);
        }
        
        // dp[u][0]: 자식 중 최소 1개 선정 필요
        if (!hasSelected) {
            if (minDiff == INT_MAX) dp[u][0] = NEG_INF; // 리프
            else dp[u][0] -= minDiff;                    // 가장 저렴한 강제 선정
        }
    }
    
    cout << max(dp[1][0], dp[1][1]) << "\n";
    return 0;
}