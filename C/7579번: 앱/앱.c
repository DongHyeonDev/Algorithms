/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 7579                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/7579                           #+#        #+#      #+#    */
/*   Solved: 2026/02/21 16:26:40 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

#define MAX_N 101
#define MAX_COST 10001   // 100 * 100

int m[MAX_N], c[MAX_N];
long long dp[MAX_COST]; // dp[j] = 비용 j로 확보 가능한 최대 메모리

long long max(long long a, long long b) {
    return a > b ? a : b;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    for (int i = 0; i < N; i++) scanf("%d", &m[i]);
    for (int i = 0; i < N; i++) scanf("%d", &c[i]);
    
    int maxCost = 0;
    for (int i = 0; i < N; i++) maxCost += c[i];
    
    memset(dp, 0, sizeof(dp));
    
    for (int i = 0; i < N; i++) {
        // 0/1 knapsack: 역순 순회
        for (int j = maxCost; j >= c[i]; j--) {
            dp[j] = max(dp[j], dp[j - c[i]] + m[i]);
        }
    }
    
    for (int cost = 0; cost <= maxCost; cost++) {
        if (dp[cost] >= M) {
            printf("%d\n", cost);
            return 0;
        }
    }
    
    return 0;
}