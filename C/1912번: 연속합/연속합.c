/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1912                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1912                           #+#        #+#      #+#    */
/*   Solved: 2025/12/04 12:36:40 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <limits.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[100000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // dp[i] = i번째 수를 포함하는 최대 연속합
    int dp[100000];
    dp[0] = arr[0];

    int max_sum = dp[0];

    for (int i = 1; i < n; i++) {
        // 현재 수만 선택 vs 이전 합에 추가
        dp[i] = max(arr[i], dp[i-1] + arr[i]);

        // 전체 최댓값 갱신
        max_sum = max(max_sum, dp[i]);
    }

    printf("%d\n", max_sum);

    return 0;
}