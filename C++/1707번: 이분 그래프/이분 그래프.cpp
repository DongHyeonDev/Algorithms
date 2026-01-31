/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1707                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1707                           #+#        #+#      #+#    */
/*   Solved: 2026/01/31 10:55:00 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<int> adj[20001];
int color[20001];

bool bfs(int start) {
    queue<int> q;
    
    q.push(start);
    color[start] = 1;
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        
        for (int next : adj[cur]) {
            if (color[next] == 0) {
                color[next] = 3 - color[cur];  // 1 -> 2, 2 -> 1
                q.push(next);
            } else if (color[next] == color[cur]) {
                return false;  // 같은 색이면 이분 그래프 아님
            }
        }
    }
    
    return true;
}

bool is_bipartite(int V) {
    memset(color, 0, sizeof(color));
    
    // 모든 정점에 대해 확인 (연결되지 않은 그래프 고려)
    for (int i = 1; i <= V; i++) {
        if (color[i] == 0) {
            if (!bfs(i)) {
                return false;
            }
        }
    }
    
    return true;
}

int main() {
    int K;
    cin >> K;
    
    while (K--) {
        int V, E;
        cin >> V >> E;
        
        for (int i = 1; i <= V; i++) {
            adj[i].clear();
        }
        
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        if (is_bipartite(V)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}