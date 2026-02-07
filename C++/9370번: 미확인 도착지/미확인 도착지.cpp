/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9370                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9370                           #+#        #+#      #+#    */
/*   Solved: 2026/02/07 16:00:13 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 2000000000

typedef pair<int, int> pii;

vector<pii> adj[2001];

vector<int> dijkstra(int start, int n) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> dist(n + 1, INF);
    
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
    int T;
    cin >> T;
    
    while (T--) {
        int n, m, t;
        cin >> n >> m >> t;
        
        int s, g, h;
        cin >> s >> g >> h;
        
        for (int i = 1; i <= n; i++) {
            adj[i].clear();
        }
        
        int gh_dist = 0;
        for (int i = 0; i < m; i++) {
            int a, b, d;
            cin >> a >> b >> d;
            adj[a].push_back({b, d});
            adj[b].push_back({a, d});
            
            if ((a == g && b == h) || (a == h && b == g)) {
                gh_dist = d;
            }
        }
        
        vector<int> targets(t);
        for (int i = 0; i < t; i++) {
            cin >> targets[i];
        }
        
        // s, g, h에서 다익스트라
        vector<int> distS = dijkstra(s, n);
        vector<int> distG = dijkstra(g, n);
        vector<int> distH = dijkstra(h, n);
        
        vector<int> result;
        
        for (int dest : targets) {
            int shortest = distS[dest];
            
            // s -> g -> h -> dest 또는 s -> h -> g -> dest
            int path1 = distS[g] + gh_dist + distH[dest];
            int path2 = distS[h] + gh_dist + distG[dest];
            
            if (shortest == path1 || shortest == path2) {
                result.push_back(dest);
            }
        }
        
        sort(result.begin(), result.end());
        
        for (int i = 0; i < result.size(); i++) {
            if (i > 0) cout << " ";
            cout << result[i];
        }
        cout << "\n";
    }
    
    return 0;
}