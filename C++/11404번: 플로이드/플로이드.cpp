/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11404                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11404                          #+#        #+#      #+#    */
/*   Solved: 2026/02/09 13:42:52 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <algorithm>

using namespace std;

#define INF 10000001

int dist[101][101];
int n, m;

void floyd_warshall() {
    // k를 거쳐가는 경로 고려
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    
    // 초기화
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                dist[i][j] = 0;
            } else {
                dist[i][j] = INF;
            }
        }
    }
    
    // 간선 정보 입력
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        // 같은 경로가 여러 개 있을 수 있으므로 최솟값 선택
        dist[a][b] = min(dist[a][b], c);
    }
    
    floyd_warshall();
    
    // 결과 출력
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dist[i][j] == INF) {
                cout << 0;
            } else {
                cout << dist[i][j];
            }
            if (j < n) cout << " ";
        }
        cout << "\n";
    }
    
    return 0;
}