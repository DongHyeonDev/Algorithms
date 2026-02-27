/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2618                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2618                           #+#        #+#      #+#    */
/*   Solved: 2026/02/27 12:31:40 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1001
#define INF 1000000000

int N, W;
int r[MAX], c[MAX];

int dp[MAX][MAX][2];
int fromJ[MAX][MAX][2];
int fromT[MAX][MAX][2];
int assignment[MAX];

int distBetween(int i, int j) {
    return abs(r[i]-r[j]) + abs(c[i]-c[j]);
}
int distFromStart(int car, int to) {
    if (car == 1) return abs(1-r[to]) + abs(1-c[to]);
    return abs(N-r[to]) + abs(N-c[to]);
}
int distFromJ(int j, int passive, int to) {
    if (j == 0) return distFromStart(passive, to);
    return distBetween(j, to);
}

int main() {
    scanf("%d %d", &N, &W);
    for (int i = 1; i <= W; i++) scanf("%d %d", &r[i], &c[i]);

    // 초기화
    for (int i = 0; i <= W; i++)
        for (int j = 0; j <= W; j++)
            dp[i][j][0] = dp[i][j][1] = INF;

    // 기저: 사건 1
    dp[1][0][0] = distFromStart(1, 1);
    dp[1][0][1] = distFromStart(2, 1);

    for (int i = 1; i < W; i++) {
        for (int j = 0; j < i; j++) {
            for (int cc = 0; cc < 2; cc++) {
                if (dp[i][j][cc] == INF) continue;
                int passive = (cc == 0) ? 2 : 1;

                // T1: 같은 차가 사건 i+1로 이동
                int cost1 = dp[i][j][cc] + distBetween(i, i+1);
                if (cost1 < dp[i+1][j][cc]) {
                    dp[i+1][j][cc] = cost1;
                    fromJ[i+1][j][cc] = j;
                    fromT[i+1][j][cc] = 1;
                }

                // T2: 반대차(passive)가 사건 i+1로 이동
                int cost2 = dp[i][j][cc] + distFromJ(j, passive, i+1);
                int nc = 1 - cc;
                if (cost2 < dp[i+1][i][nc]) {
                    dp[i+1][i][nc] = cost2;
                    fromJ[i+1][i][nc] = j;
                    fromT[i+1][i][nc] = 2;
                }
            }
        }
    }

    // 최솟값 탐색
    int ans = INF, bestJ = 0, bestC = 0;
    for (int j = 0; j < W; j++)
        for (int cc = 0; cc < 2; cc++)
            if (dp[W][j][cc] < ans) {
                ans = dp[W][j][cc];
                bestJ = j; bestC = cc;
            }

    printf("%d\n", ans);

    // 역추적
    int ci = W, cj = bestJ, cc = bestC;
    while (ci >= 1) {
        assignment[ci] = cc + 1;
        int t = fromT[ci][cj][cc];
        if (t == 0) break;
        int pj = fromJ[ci][cj][cc];
        if (t == 1) {
            ci--;
        } else {
            int pi = ci - 1;
            ci = pi; cj = pj; cc = 1 - cc;
        }
    }

    for (int i = 1; i <= W; i++) printf("%d\n", assignment[i]);
    return 0;
}