/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11780                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11780                          #+#        #+#      #+#    */
/*   Solved: 2026/03/03 18:35:39 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_N 101
#define INF   1000000000

int n, m;
int dist[MAX_N][MAX_N];
int via[MAX_N][MAX_N];   // via[i][j] = i→j 최단경로의 경유 노드 (-1이면 직접 연결)
int path[MAX_N * MAX_N];
int pathLen;

void getPath(int i, int j) {
    if (via[i][j] == -1) {
        // 직접 연결: i, j 순으로 추가 (중복 방지는 호출부에서)
        path[pathLen++] = i;
        path[pathLen++] = j;
    } else {
        int k = via[i][j];
        getPath(i, k);
        pathLen--; // k 중복 제거 (getPath(i,k)의 마지막이 k)
        getPath(k, j);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            dist[i][j] = (i == j) ? 0 : INF;
            via[i][j] = -1;
        }
    
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if (c < dist[a][b]) dist[a][b] = c;
    }
    
    // 플로이드-워셜
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] == INF || dist[k][j] == INF) continue;
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    via[i][j] = k;
                }
            }
    
    // 비용 행렬 출력
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d", dist[i][j] == INF ? 0 : dist[i][j]);
            if (j < n) printf(" ");
        }
        printf("\n");
    }
    
    // 경로 행렬 출력
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j || dist[i][j] == INF) {
                printf("0\n");
            } else {
                pathLen = 0;
                getPath(i, j);
                printf("%d", pathLen);
                for (int p = 0; p < pathLen; p++) printf(" %d", path[p]);
                printf("\n");
            }
        }
    }
    
    return 0;
}