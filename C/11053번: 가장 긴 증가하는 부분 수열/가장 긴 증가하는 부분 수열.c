/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11053                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11053                          #+#        #+#      #+#    */
/*   Solved: 2025/12/11 13:38:32 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int N;
    scanf("%d", &N);

    int A[1000];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // dp[i] = i번째 원소를 마지막으로 하는 LIS의 길이
    int dp[1000];

    // 초기화
    for (int i = 0; i < N; i++) {
        dp[i] = 1;  // 자기 자신만 포함
    }

    // DP 계산
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            // A[j] < A[i]이면 A[j] 뒤에 A[i]를 붙일 수 있음
            if (A[j] < A[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // 최댓값 찾기
    int result = 0;
    for (int i = 0; i < N; i++) {
        result = max(result, dp[i]);
    }

    printf("%d\n", result);

    return 0;
}