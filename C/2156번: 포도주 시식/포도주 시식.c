/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2156                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2156                           #+#        #+#      #+#    */
/*   Solved: 2025/12/10 15:38:47 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int max3(int a, int b, int c) {
    return max(max(a, b), c);
}

int main() {
    int n;
    scanf("%d", &n);

    int wine[10001];
    for (int i = 1; i <= n; i++) {
        scanf("%d", &wine[i]);
    }

    // dp[i] = i번째 잔까지 고려했을 때 최대 포도주 양
    int dp[10001] = {0};

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
        dp[i] = max3(
            dp[i-1],
            dp[i-2] + wine[i],
            dp[i-3] + wine[i-1] + wine[i]
        );
    }

    printf("%d\n", dp[n]);

    return 0;
}