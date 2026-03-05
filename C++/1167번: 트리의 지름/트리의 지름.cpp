/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1167                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1167                           #+#        #+#      #+#    */
/*   Solved: 2026/03/05 16:35:52 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int V;
vector<pair<int,int>> graph[100001]; // (노드, 거리)

// BFS: src에서 가장 먼 노드와 거리 배열 반환
pair<int, vector<int>> bfs(int src) {
    vector<int> dist(V + 1, -1);
    queue<int> q;
    dist[src] = 0;
    q.push(src);
    
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto [v, w] : graph[u]) {
            if (dist[v] != -1) continue;
            dist[v] = dist[u] + w;
            q.push(v);
        }
    }
    
    int farthest = src;
    for (int i = 1; i <= V; i++)
        if (dist[i] > dist[farthest]) farthest = i;
    
    return {farthest, dist};
}

int main() {
    cin >> V;
    
    for (int i = 0; i < V; i++) {
        int u;
        cin >> u;
        int v;
        while (cin >> v && v != -1) {
            int w; cin >> w;
            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }
    }
    
    auto [u, _]     = bfs(1);  // 1에서 가장 먼 노드 u
    auto [__, dist] = bfs(u);  // u에서 가장 먼 거리 = 지름
    
    cout << *max_element(dist.begin() + 1, dist.end()) << "\n";
    
    return 0;
}