/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11780                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11780                          #+#        #+#      #+#    */
/*   Solved: 2026/03/03 18:35:45 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int INF = 1e9;
int n, m;
int dist[101][101];
int via[101][101];  // via[i][j] = i→j 최단경로의 경유 노드

// i→j 경로를 재귀적으로 복원
vector<int> getPath(int i, int j) {
    if (via[i][j] == -1) return {i, j};  // 직접 연결
    int k = via[i][j];
    auto left  = getPath(i, k);
    auto right = getPath(k, j);
    // left의 끝(=k)과 right의 시작(=k) 중복 제거
    left.insert(left.end(), right.begin() + 1, right.end());
    return left;
}

int main() {
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            dist[i][j] = (i == j) ? 0 : INF;
            via[i][j]  = -1;
        }
    
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (c < dist[a][b]) dist[a][b] = c;  // 중복 간선: 최솟값 유지
    }
    
    // 플로이드-워셜
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] == INF || dist[k][j] == INF) continue;
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    via[i][j]  = k;  // i→j는 k를 경유
                }
            }
    
    // 비용 행렬 출력
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << (dist[i][j] == INF ? 0 : dist[i][j]);
            cout << (j == n ? "\n" : " ");
        }
    }
    
    // 경로 행렬 출력
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j || dist[i][j] == INF) {
                cout << "0\n";
            } else {
                auto path = getPath(i, j);
                cout << path.size();
                for (int v : path) cout << " " << v;
                cout << "\n";
            }
        }
    }
    
    return 0;
}