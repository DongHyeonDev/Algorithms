/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 24480                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/24480                          #+#        #+#      #+#    */
/*   Solved: 2026/01/17 21:57:38 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graph[100001];
int visited[100001];
int order_count = 1;

void dfs(int node) {
    visited[node] = order_count++;
    
    for (int next : graph[node]) {
        if (visited[next] == 0) {
            dfs(next);
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
    
    // DFS 시작
    dfs(R);
    
    // 결과 출력
    for (int i = 1; i <= N; i++) {
        cout << visited[i] << "\n";
    }
    
    return 0;
}