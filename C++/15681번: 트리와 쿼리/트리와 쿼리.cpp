/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 15681                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/15681                          #+#        #+#      #+#    */
/*   Solved: 2026/03/21 17:06:34 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int N, R, Q;
    cin >> N >> R >> Q;
    
    vector<vector<int>> graph(N + 1);
    for (int i = 0; i < N - 1; i++) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    vector<int> par(N + 1, 0);
    vector<int> sz(N + 1, 1);
    vector<int> order;
    order.reserve(N);
    
    // BFS로 방문 순서 기록 + 부모 설정
    vector<bool> visited(N + 1, false);
    queue<int> q;
    visited[R] = true;
    q.push(R);
    
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (int v : graph[u]) {
            if (visited[v]) continue;
            visited[v] = true;
            par[v] = u;
            q.push(v);
        }
    }
    
    // 역순으로 size 누적 (리프 → 루트 방향)
    for (int i = (int)order.size() - 1; i >= 0; i--) {
        int u = order[i];
        if (par[u]) sz[par[u]] += sz[u];
    }
    
    for (int i = 0; i < Q; i++) {
        int u; cin >> u;
        cout << sz[u] << "\n";
    }
    
    return 0;
}