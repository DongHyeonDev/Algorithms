/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11049                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11049                          #+#        #+#      #+#    */
/*   Solved: 2026/02/17 16:24:56 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

#define INF 2147483647

int r[501], c[501];       // 각 행렬의 행, 열 크기
long long dp[501][501];   // dp[i][j] = i번째부터 j번째 행렬을 곱하는 최소 연산 수
int N;

long long min(long long a, long long b) {
    return a < b ? a : b;
}

int main() {
    scanf("%d", &N);
    
    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &r[i], &c[i]);
    }
    
    // DP 초기화
    memset(dp, 0, sizeof(dp));
    
    // 길이별로 DP
    for (int len = 2; len <= N; len++) {
        for (int i = 1; i + len - 1 <= N; i++) {
            int j = i + len - 1;
            dp[i][j] = INF;
            
            // i부터 j까지 행렬을 곱하는 최소 연산 수
            // k를 기준으로 [i..k]와 [k+1..j]로 분할
            for (int k = i; k < j; k++) {
                long long cost = dp[i][k] + dp[k + 1][j] + (long long)r[i] * c[k] * c[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    
    printf("%lld\n", dp[1][N]);
    
    return 0;
}