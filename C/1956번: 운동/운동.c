/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1956                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1956                           #+#        #+#      #+#    */
/*   Solved: 2026/02/10 11:44:28 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

#define INF 10000001
#define MAX_V 401

int dist[MAX_V][MAX_V];
int V, E;

int min(int a, int b) {
    return a < b ? a : b;
}

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
    scanf("%d %d", &V, &E);
    
    // 초기화
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            dist[i][j] = INF;
        }
    }
    
    // 간선 정보 입력
    for (int i = 0; i < E; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        dist[a][b] = c;
    }
    
    int result = floyd_warshall();
    
    if (result == INF) {
        printf("-1\n");
    } else {
        printf("%d\n", result);
    }
    
    return 0;
}