/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11657                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11657                          #+#        #+#      #+#    */
/*   Solved: 2026/02/08 18:25:58 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

#define INF 1000000000
#define MAX_N 501
#define MAX_M 6001

typedef struct {
    int from, to, cost;
} Edge;

Edge edges[MAX_M];
long long dist[MAX_N];
int N, M;

int bellman_ford() {
    // 초기화
    for (int i = 1; i <= N; i++) {
        dist[i] = INF;
    }
    dist[1] = 0;
    
    // N-1번 반복하여 최단 거리 갱신
    for (int i = 1; i <= N - 1; i++) {
        for (int j = 0; j < M; j++) {
            int u = edges[j].from;
            int v = edges[j].to;
            int w = edges[j].cost;
            
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
    
    // 음수 사이클 검사
    for (int j = 0; j < M; j++) {
        int u = edges[j].from;
        int v = edges[j].to;
        int w = edges[j].cost;
        
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            return 1;  // 음수 사이클 존재
        }
    }
    
    return 0;  // 음수 사이클 없음
}

int main() {
    scanf("%d %d", &N, &M);
    
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &edges[i].from, &edges[i].to, &edges[i].cost);
    }
    
    int has_negative_cycle = bellman_ford();
    
    if (has_negative_cycle) {
        printf("-1\n");
    } else {
        for (int i = 2; i <= N; i++) {
            if (dist[i] == INF) {
                printf("-1\n");
            } else {
                printf("%lld\n", dist[i]);
            }
        }
    }
    
    return 0;
}