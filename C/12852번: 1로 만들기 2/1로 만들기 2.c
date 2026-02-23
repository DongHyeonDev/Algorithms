/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 12852                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/12852                          #+#        #+#      #+#    */
/*   Solved: 2026/02/23 11:32:53 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

#define MAX_N 1000001

int dp[MAX_N];
int from[MAX_N];  // from[i] = i로부터 다음에 올 숫자 (역추적용)
int path[MAX_N];

int min(int a, int b) { return a < b ? a : b; }

int main() {
    int N;
    scanf("%d", &N);
    
    // 초기화
    for (int i = 2; i <= N; i++) dp[i] = 1e9;
    dp[1] = 0;

    for (int i = 2; i <= N; i++) {
        // 연산 3: 1 빼기
        dp[i] = dp[i - 1] + 1;
        from[i] = i - 1;

        // 연산 2: 2로 나누기
        if (i % 2 == 0 && dp[i / 2] + 1 < dp[i]) {
            dp[i] = dp[i / 2] + 1;
            from[i] = i / 2;
        }

        // 연산 1: 3으로 나누기
        if (i % 3 == 0 && dp[i / 3] + 1 < dp[i]) {
            dp[i] = dp[i / 3] + 1;
            from[i] = i / 3;
        }
    }
    
    printf("%d\n", dp[N]);

    // 역추적
    int len = 0, cur = N;
    while (cur != 0) {
        path[len++] = cur;
        cur = from[cur];
    }
    for (int i = 0; i < len; i++) {
        printf("%d", path[i]);
        if (i < len - 1) printf(" ");
    }
    printf("\n");

    return 0;
}