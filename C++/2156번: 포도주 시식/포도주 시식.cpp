/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2156                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2156                           #+#        #+#      #+#    */
/*   Solved: 2025/12/10 15:38:53 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> wine(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> wine[i];
    }

    // dp[i] = i번째 잔까지 고려했을 때 최대 포도주 양
    vector<int> dp(n + 1, 0);

    // 초기값
    dp[1] = wine[1];
    if (n >= 2) {
        dp[2] = wine[1] + wine[2];
    }

    // DP 계산
    for (int i = 3; i <= n; i++) {
        // 경우 1: i번째 안 마심
        // 경우 2: i번째만 마심 (i-1번 안 마심)
        // 경우 3: i-1번, i번 연속 마심 (i-2번 안 마심)
        dp[i] = max({
            dp[i-1],
            dp[i-2] + wine[i],
            dp[i-3] + wine[i-1] + wine[i]
        });
    }

    cout << dp[n] << "\n";

    return 0;
}