/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11725                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11725                          #+#        #+#      #+#    */
/*   Solved: 2026/03/04 13:04:45 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<vector<int>> graph(N + 1);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    vector<int> parent(N + 1, 0);
    vector<bool> visited(N + 1, false);
    
    // BFS (루트: 1)
    queue<int> q;
    visited[1] = true;
    q.push(1);
    
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : graph[u]) {
            if (visited[v]) continue;
            visited[v] = true;
            parent[v] = u;   // u가 v의 부모
            q.push(v);
        }
    }
    
    for (int i = 2; i <= N; i++) cout << parent[i] << "\n";
    
    return 0;
}