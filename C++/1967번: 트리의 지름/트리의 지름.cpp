/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1967                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1967                           #+#        #+#      #+#    */
/*   Solved: 2026/03/06 14:09:28 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int V;
vector<pair<int,int>> graph[10001];

pair<int, int> bfs(int src) {
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
    
    return {farthest, dist[farthest]};
}

int main() {
    cin >> V;
    
    for (int i = 0; i < V - 1; i++) {
        int p, c, w;
        cin >> p >> c >> w;
        graph[p].push_back({c, w});
        graph[c].push_back({p, w});
    }
    
    auto [u, _]        = bfs(1);  // 1에서 가장 먼 노드 u
    auto [__, diameter] = bfs(u); // u에서 가장 먼 거리 = 지름
    
    cout << diameter << "\n";
    
    return 0;
}