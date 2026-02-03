/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1766                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1766                           #+#        #+#      #+#    */
/*   Solved: 2026/02/03 12:21:32 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[32001];
int indegree[32001];

void topology_sort(int N) {
    priority_queue<int, vector<int>, greater<int>> pq;  // 최소 힙
    vector<int> result;
    
    // 진입 차수가 0인 정점을 우선순위 큐에 넣기
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            pq.push(i);
        }
    }
    
    while (!pq.empty()) {
        int cur = pq.top();
        pq.pop();
        result.push_back(cur);
        
        // 현재 정점과 연결된 정점들의 진입 차수 감소
        for (int next : adj[cur]) {
            indegree[next]--;
            
            if (indegree[next] == 0) {
                pq.push(next);
            }
        }
    }
    
    // 결과 출력
    for (int i = 0; i < result.size(); i++) {
        if (i > 0) cout << " ";
        cout << result[i];
    }
    cout << "\n";
}

int main() {
    int N, M;
    cin >> N >> M;
    
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        indegree[B]++;
    }
    
    topology_sort(N);
    
    return 0;
}