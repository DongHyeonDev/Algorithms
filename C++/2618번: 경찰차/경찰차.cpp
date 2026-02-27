/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2618                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2618                           #+#        #+#      #+#    */
/*   Solved: 2026/02/27 12:31:46 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int INF = 1e9;
int N, W;
int r[1001], c[1001];

// dp[i][j][c]: 사건i에 (c+1)번차, 사건j에 반대차 (j=0이면 출발지)
int dp[1001][1001][2];
int fromJ[1001][1001][2];
int fromT[1001][1001][2]; // 0=기저, 1=같은차, 2=반대차

int distBetween(int i, int j) {
    return abs(r[i]-r[j]) + abs(c[i]-c[j]);
}
int distFromStart(int car, int to) {
    if (car == 1) return abs(1-r[to]) + abs(1-c[to]);
    return abs(N-r[to]) + abs(N-c[to]);
}
int distFromJ(int j, int passive, int to) {
    return j == 0 ? distFromStart(passive, to) : distBetween(j, to);
}

int main() {
    cin >> N >> W;
    for (int i = 1; i <= W; i++) cin >> r[i] >> c[i];

    for (int i = 0; i <= W; i++)
        for (int j = 0; j <= W; j++)
            dp[i][j][0] = dp[i][j][1] = INF;

    // 기저: 사건 1을 1번차 또는 2번차가 처리
    dp[1][0][0] = distFromStart(1, 1);
    dp[1][0][1] = distFromStart(2, 1);

    for (int i = 1; i < W; i++) {
        for (int j = 0; j < i; j++) {
            for (int cc = 0; cc < 2; cc++) {
                if (dp[i][j][cc] == INF) continue;
                int passive = (cc == 0) ? 2 : 1;

                // T1: 활성차(cc+1)가 사건 i+1로 이동
                int cost1 = dp[i][j][cc] + distBetween(i, i+1);
                if (cost1 < dp[i+1][j][cc]) {
                    dp[i+1][j][cc] = cost1;
                    fromJ[i+1][j][cc] = j;
                    fromT[i+1][j][cc] = 1;
                }

                // T2: 수동차(passive)가 사건 i+1로 이동, 역할 교환
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

    int ans = INF, bestJ = 0, bestC = 0;
    for (int j = 0; j < W; j++)
        for (int cc = 0; cc < 2; cc++)
            if (dp[W][j][cc] < ans) {
                ans = dp[W][j][cc];
                bestJ = j; bestC = cc;
            }

    cout << ans << "\n";

    // 역추적
    vector<int> assignment(W+1);
    int ci = W, cj = bestJ, cc = bestC;
    while (ci >= 1) {
        assignment[ci] = cc + 1;
        int t = fromT[ci][cj][cc];
        if (t == 0) break;
        int pj = fromJ[ci][cj][cc];
        if (t == 1) {
            ci--;            // cj, cc 유지
        } else {
            int pi = ci - 1;
            ci = pi; cj = pj; cc = 1 - cc; // 역할 교환 복구
        }
    }

    for (int i = 1; i <= W; i++) cout << assignment[i] << "\n";
    return 0;
}