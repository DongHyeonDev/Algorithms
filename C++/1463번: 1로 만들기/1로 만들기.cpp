/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1463                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1463                           #+#        #+#      #+#    */
/*   Solved: 2025/12/08 14:25:02 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    // dp[i] = i를 1로 만드는 최소 연산 횟수
    vector<int> dp(N + 1);

    // 초기값
    dp[1] = 0;

    // DP 계산
    for (int i = 2; i <= N; i++) {
        // 기본: 1 빼기
        dp[i] = dp[i-1] + 1;

        // 2로 나누기
        if (i % 2 == 0) {
            dp[i] = min(dp[i], dp[i/2] + 1);
        }

        // 3으로 나누기
        if (i % 3 == 0) {
            dp[i] = min(dp[i], dp[i/3] + 1);
        }
    }

    cout << dp[N] << "\n";

    return 0;
}