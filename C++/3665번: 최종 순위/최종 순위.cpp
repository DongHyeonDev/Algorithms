/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 3665                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/3665                           #+#        #+#      #+#    */
/*   Solved: 2026/02/02 12:36:15 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
int last_year[501];
int graph[501][501];  // graph[i][j] = 1이면 i가 j보다 순위가 높음
int indegree[501];

int topology_sort(vector<int>& result) {
    queue<int> q;
    
    // 진입 차수가 0인 정점 찾기
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    
    while (!q.empty()) {
        // 큐에 원소가 2개 이상이면 순위를 확정할 수 없음
        if (q.size() > 1) {
            return -1;  // 확실한 순위를 찾을 수 없음
        }
        
        int cur = q.front();
        q.pop();
        result.push_back(cur);
        
        for (int next = 1; next <= n; next++) {
            if (graph[cur][next]) {
                indegree[next]--;
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }
    }
    
    // 모든 정점을 방문하지 못했으면 사이클 존재
    if (result.size() != n) {
        return 0;  // IMPOSSIBLE
    }
    
    return 1;  // 성공
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        cin >> n;
        
        memset(graph, 0, sizeof(graph));
        memset(indegree, 0, sizeof(indegree));
        
        // 작년 순위 입력
        for (int i = 0; i < n; i++) {
            cin >> last_year[i];
        }
        
        // 작년 순위를 기반으로 그래프 생성
        // 순위가 높은 팀 -> 낮은 팀으로 간선
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                graph[last_year[i]][last_year[j]] = 1;
                indegree[last_year[j]]++;
            }
        }
        
        cin >> m;
        
        // 상대적 순위가 바뀐 쌍 처리
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            
            // 간선 방향 뒤집기
            if (graph[a][b]) {
                graph[a][b] = 0;
                graph[b][a] = 1;
                indegree[b]--;
                indegree[a]++;
            } else {
                graph[b][a] = 0;
                graph[a][b] = 1;
                indegree[a]--;
                indegree[b]++;
            }
        }
        
        vector<int> result;
        int res = topology_sort(result);
        
        if (res == 0) {
            cout << "IMPOSSIBLE\n";
        } else if (res == -1) {
            cout << "?\n";
        } else {
            for (int i = 0; i < result.size(); i++) {
                if (i > 0) cout << " ";
                cout << result[i];
            }
            cout << "\n";
        }
    }
    
    return 0;
}