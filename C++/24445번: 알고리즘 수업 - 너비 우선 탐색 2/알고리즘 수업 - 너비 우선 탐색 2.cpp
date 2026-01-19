/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 24445                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/24445                          #+#        #+#      #+#    */
/*   Solved: 2026/01/19 14:54:10 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> graph[100001];
int visited[100001];
int order_count = 1;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = order_count++;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        for (int next : graph[node]) {
            if (visited[next] == 0) {
                visited[next] = order_count++;
                q.push(next);
            }
        }
    }
}

int main() {
    int N, M, R;
    cin >> N >> M >> R;
    
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    // 인접 리스트를 내림차순 정렬
    for (int i = 1; i <= N; i++) {
        sort(graph[i].begin(), graph[i].end(), greater<int>());
    }
    
    // BFS 시작
    bfs(R);
    
    // 결과 출력
    for (int i = 1; i <= N; i++) {
        cout << visited[i] << "\n";
    }
    
    return 0;
}