/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2213                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2213                           #+#        #+#      #+#    */
/*   Solved: 2026/03/24 03:49:35 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> w(N+1);
    for (int i=1;i<=N;i++) cin >> w[i];
    
    vector<vector<int>> graph(N+1);
    int u, v;
    while (cin >> u >> v) {
        graph[u].push_back(v); graph[v].push_back(u);
    }
    
    vector<int> par(N+1,0), order;
    vector<array<int,2>> dp(N+1, {0,0});
    vector<bool> visited(N+1,false);
    order.reserve(N);
    
    // BFS
    queue<int> q;
    q.push(1); visited[1]=true;
    while (!q.empty()) {
        int u=q.front(); q.pop(); order.push_back(u);
        for (int v:graph[u]) if (!visited[v]) {
            visited[v]=true; par[v]=u; q.push(v);
        }
    }
    
    // 역순 DP
    for (int i=(int)order.size()-1;i>=0;i--) {
        int u=order[i];
        dp[u][1]=w[u]; dp[u][0]=0;
        for (int c:graph[u]) {
            if (c==par[u]) continue;
            dp[u][1] += dp[c][0];
            dp[u][0] += max(dp[c][0], dp[c][1]);
        }
    }
    
    cout << max(dp[1][0], dp[1][1]) << "\n";
    
    // 역추적: 루트에서 아래로 상태 결정
    vector<int> stateArr(N+1, 0);
    vector<bool> selected(N+1, false);
    stateArr[1] = dp[1][1] >= dp[1][0] ? 1 : 0;
    if (stateArr[1]) selected[1] = true;
    
    for (int u : order) {
        for (int c : graph[u]) {
            if (c == par[u]) continue;
            if (stateArr[u] == 1) {
                stateArr[c] = 0;           // 부모 선정 → 자식 미선정
            } else {
                stateArr[c] = dp[c][1] >= dp[c][0] ? 1 : 0; // 더 좋은 쪽
            }
            if (stateArr[c]) selected[c] = true;
        }
    }
    
    bool first = true;
    for (int i=1;i<=N;i++) if (selected[i]) {
        if (!first) cout << " ";
        cout << i; first = false;
    }
    cout << "\n";
    
    return 0;
}