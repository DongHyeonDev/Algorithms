/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1149                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1149                           #+#        #+#      #+#    */
/*   Solved: 2025/12/05 12:03:56 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> cost(N, vector<int>(3));

    for (int i = 0; i < N; i++) {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }

    // dp[i][j] = i번째 집을 j색으로 칠했을 때의 최소 비용
    vector<vector<int>> dp(N, vector<int>(3));

    // 초기값: 첫 번째 집
    dp[0][0] = cost[0][0];  // 빨강
    dp[0][1] = cost[0][1];  // 초록
    dp[0][2] = cost[0][2];  // 파랑

    // DP 계산
    for (int i = 1; i < N; i++) {
        // i번 집을 빨강으로: 이전 집은 초록 또는 파랑
        dp[i][0] = cost[i][0] + min(dp[i-1][1], dp[i-1][2]);

        // i번 집을 초록으로: 이전 집은 빨강 또는 파랑
        dp[i][1] = cost[i][1] + min(dp[i-1][0], dp[i-1][2]);

        // i번 집을 파랑으로: 이전 집은 빨강 또는 초록
        dp[i][2] = cost[i][2] + min(dp[i-1][0], dp[i-1][1]);
    }

    // 마지막 집의 최소 비용
    int result = min({dp[N-1][0], dp[N-1][1], dp[N-1][2]});

    cout << result << "\n";

    return 0;
}