/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2579                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2579                           #+#        #+#      #+#    */
/*   Solved: 2025/12/07 16:28:23 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n;
    scanf("%d", &n);

    int stairs[301];
    for (int i = 1; i <= n; i++) {
        scanf("%d", &stairs[i]);
    }

    // dp[i] = i번째 계단까지의 최대 점수
    int dp[301] = {0};

    // 초기값
    dp[1] = stairs[1];
    if (n >= 2) {
        dp[2] = stairs[1] + stairs[2];
    }

    // DP 계산
    for (int i = 3; i <= n; i++) {
        // 경우 1: i-3 -> i-1 -> i (연속 2칸)
        // 경우 2: i-2 -> i (2칸 점프)
        dp[i] = max(dp[i-3] + stairs[i-1] + stairs[i],
                    dp[i-2] + stairs[i]);
    }

    printf("%d\n", dp[n]);

    return 0;
}