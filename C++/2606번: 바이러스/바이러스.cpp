/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2606                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2606                           #+#        #+#      #+#    */
/*   Solved: 2026/01/20 13:15:33 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[101];
bool visited[101];
int count_infected = 0;

void dfs(int node) {
    visited[node] = true;
    count_infected++;
    
    for (int next : graph[node]) {
        if (!visited[next]) {
            dfs(next);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    // 1번 컴퓨터에서 DFS 시작
    dfs(1);
    
    // 1번 컴퓨터는 제외하고 출력
    cout << count_infected - 1 << "\n";
    
    return 0;
}