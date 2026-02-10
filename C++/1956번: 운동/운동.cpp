/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1956                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1956                           #+#        #+#      #+#    */
/*   Solved: 2026/02/10 11:44:39 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <algorithm>

using namespace std;

#define INF 10000001

int dist[401][401];
int V, E;

int floyd_warshall() {
    // k를 거쳐가는 경로 고려
    for (int k = 1; k <= V; k++) {
        for (int i = 1; i <= V; i++) {
            for (int j = 1; j <= V; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    
    // 최소 사이클 찾기
    int min_cycle = INF;
    for (int i = 1; i <= V; i++) {
        min_cycle = min(min_cycle, dist[i][i]);
    }
    
    return min_cycle;
}

int main() {
    cin >> V >> E;
    
    // 초기화
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            dist[i][j] = INF;
        }
    }
    
    // 간선 정보 입력
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = c;
    }
    
    int result = floyd_warshall();
    
    if (result == INF) {
        cout << "-1\n";
    } else {
        cout << result << "\n";
    }
    
    return 0;
}