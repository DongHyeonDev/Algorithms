/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 14002                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/14002                          #+#        #+#      #+#    */
/*   Solved: 2026/02/24 11:33:13 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

#define MAX_N 1001

int A[MAX_N];
int dp[MAX_N];    // dp[i] = i에서 끝나는 LIS 길이
int from[MAX_N];  // from[i] = LIS에서 i 이전 인덱스
int path[MAX_N];

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);

    for (int i = 0; i < N; i++) {
        dp[i] = 1;
        from[i] = -1;
    }

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (A[j] < A[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                from[i] = j;
            }
        }
    }

    // LIS 길이 및 끝 인덱스 탐색
    int maxLen = 0, endIdx = 0;
    for (int i = 0; i < N; i++) {
        if (dp[i] > maxLen) {
            maxLen = dp[i];
            endIdx = i;
        }
    }

    printf("%d\n", maxLen);

    // 역추적
    int len = 0, cur = endIdx;
    while (cur != -1) {
        path[len++] = A[cur];
        cur = from[cur];
    }
    for (int i = len - 1; i >= 0; i--) {
        printf("%d", path[i]);
        if (i > 0) printf(" ");
    }
    printf("\n");

    return 0;
}