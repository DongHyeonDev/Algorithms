/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1932                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1932                           #+#        #+#      #+#    */
/*   Solved: 2025/12/06 14:54:52 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n;
    scanf("%d", &n);

    int triangle[500][500];

    // 삼각형 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            scanf("%d", &triangle[i][j]);
        }
    }

    // dp[i][j] = (i, j) 위치까지의 최대 합
    int dp[500][500];

    // 초기값: 맨 위
    dp[0][0] = triangle[0][0];

    // DP 계산
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            // 가장 왼쪽 (j=0)
            if (j == 0) {
                dp[i][j] = dp[i-1][j] + triangle[i][j];
            }
            // 가장 오른쪽 (j=i)
            else if (j == i) {
                dp[i][j] = dp[i-1][j-1] + triangle[i][j];
            }
            // 중간 위치
            else {
                dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
            }
        }
    }

    // 마지막 행에서 최댓값 찾기
    int result = dp[n-1][0];
    for (int j = 1; j < n; j++) {
        result = max(result, dp[n-1][j]);
    }

    printf("%d\n", result);

    return 0;
}