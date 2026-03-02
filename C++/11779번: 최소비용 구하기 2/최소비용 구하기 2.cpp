/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11779                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11779                          #+#        #+#      #+#    */
/*   Solved: 2026/03/02 21:15:18 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<int,int>>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    
    int A, B;
    cin >> A >> B;
    
    vector<int> dist(n + 1, INF);
    vector<int> from(n + 1, -1);
    
    // 우선순위 큐 기반 다익스트라
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    dist[A] = 0;
    pq.push({0, A});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;  // 이미 처리된 노드
        
        for (auto [v, w] : graph[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                from[v] = u;           // 역추적 기록
                pq.push({dist[v], v});
            }
        }
    }
    
    cout << dist[B] << "\n";
    
    // 역추적: B → A 방향으로 from 따라가기
    vector<int> path;
    int cur = B;
    while (cur != -1) {
        path.push_back(cur);
        cur = from[cur];
    }
    reverse(path.begin(), path.end());
    
    cout << path.size() << "\n";
    for (int i = 0; i < (int)path.size(); i++) {
        cout << path[i];
        if (i + 1 < (int)path.size()) cout << " ";
    }
    cout << "\n";
    
    return 0;
}