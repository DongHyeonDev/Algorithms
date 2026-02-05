/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1504                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1504                           #+#        #+#      #+#    */
/*   Solved: 2026/02/05 12:45:24 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 200000000

typedef pair<int, int> pii;

vector<pii> adj[801];

vector<int> dijkstra(int start, int N) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> dist(N + 1, INF);
    
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto& edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    
    return dist;
}

int main() {
    int N, E;
    cin >> N >> E;
    
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    
    int v1, v2;
    cin >> v1 >> v2;
    
    // 1, v1, v2에서 각각 다익스트라 수행
    vector<int> dist1 = dijkstra(1, N);
    vector<int> distV1 = dijkstra(v1, N);
    vector<int> distV2 = dijkstra(v2, N);
    
    // 경로1: 1 -> v1 -> v2 -> N
    // 경로2: 1 -> v2 -> v1 -> N
    int path1 = dist1[v1] + distV1[v2] + distV2[N];
    int path2 = dist1[v2] + distV2[v1] + distV1[N];
    
    int answer = min(path1, path2);
    
    if (answer >= INF) {
        cout << "-1\n";
    } else {
        cout << answer << "\n";
    }
    
    return 0;
}