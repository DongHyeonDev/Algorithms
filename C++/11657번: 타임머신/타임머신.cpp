/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11657                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11657                          #+#        #+#      #+#    */
/*   Solved: 2026/02/08 18:26:05 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define INF 1000000000

typedef struct {
    int from, to, cost;
} Edge;

int N, M;
vector<Edge> edges;
long long dist[501];

bool bellman_ford() {
    // 초기화
    for (int i = 1; i <= N; i++) {
        dist[i] = INF;
    }
    dist[1] = 0;
    
    // N-1번 반복하여 최단 거리 갱신
    for (int i = 1; i <= N - 1; i++) {
        for (const Edge& e : edges) {
            if (dist[e.from] != INF && dist[e.from] + e.cost < dist[e.to]) {
                dist[e.to] = dist[e.from] + e.cost;
            }
        }
    }
    
    // 음수 사이클 검사
    for (const Edge& e : edges) {
        if (dist[e.from] != INF && dist[e.from] + e.cost < dist[e.to]) {
            return true;  // 음수 사이클 존재
        }
    }
    
    return false;  // 음수 사이클 없음
}

int main() {
    cin >> N >> M;
    
    edges.resize(M);
    for (int i = 0; i < M; i++) {
        cin >> edges[i].from >> edges[i].to >> edges[i].cost;
    }
    
    bool has_negative_cycle = bellman_ford();
    
    if (has_negative_cycle) {
        cout << "-1\n";
    } else {
        for (int i = 2; i <= N; i++) {
            if (dist[i] == INF) {
                cout << "-1\n";
            } else {
                cout << dist[i] << "\n";
            }
        }
    }
    
    return 0;
}