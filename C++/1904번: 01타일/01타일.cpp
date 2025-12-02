/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1904                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1904                           #+#        #+#      #+#    */
/*   Solved: 2025/12/02 13:04:32 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 15746;

int main() {
    int N;
    cin >> N;

    // dp[i] = 길이 i인 수열의 경우의 수
    vector<int> dp(N + 1);

    // 초기값
    dp[1] = 1;
    if (N >= 2) {
        dp[2] = 2;
    }

    // 동적 프로그래밍
    for (int i = 3; i <= N; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % MOD;
    }

    cout << dp[N] << "\n";

    return 0;
}