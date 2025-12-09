/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10844                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10844                          #+#        #+#      #+#    */
/*   Solved: 2025/12/09 15:29:22 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1000000000;

int main() {
    int N;
    cin >> N;

    // dp[i][j] = 길이가 i이고 마지막 자리가 j인 계단 수의 개수
    vector<vector<long long>> dp(N + 1, vector<long long>(10, 0));

    // 길이 1: 1~9로 시작 (0 제외)
    for (int i = 1; i <= 9; i++) {
        dp[1][i] = 1;
    }

    // DP 계산
    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= 9; j++) {
            // j로 끝나려면 이전 자리는 j-1 또는 j+1
            if (j > 0) {
                dp[i][j] += dp[i-1][j-1];
            }
            if (j < 9) {
                dp[i][j] += dp[i-1][j+1];
            }
            dp[i][j] %= MOD;
        }
    }

    // 길이 N인 모든 계단 수의 합
    long long result = 0;
    for (int j = 0; j <= 9; j++) {
        result += dp[N][j];
        result %= MOD;
    }

    cout << result << "\n";

    return 0;
}