/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11062                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11062                          #+#        #+#      #+#    */
/*   Solved: 2026/02/22 16:25:02 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

#define MAX_N 1001

int cards[MAX_N];
long long dp[MAX_N][MAX_N];
long long prefix[MAX_N];

long long min(long long a, long long b) { return a < b ? a : b; }

int main() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        int N;
        scanf("%d", &N);
        
        prefix[0] = 0;
        for (int i = 0; i < N; i++) {
            scanf("%d", &cards[i]);
            prefix[i + 1] = prefix[i] + cards[i];
        }
        
        memset(dp, 0, sizeof(dp));
        
        // 기저: 카드 1장
        for (int i = 0; i < N; i++) {
            dp[i][i] = cards[i];
        }
        
        for (int len = 2; len <= N; len++) {
            for (int i = 0; i + len - 1 < N; i++) {
                int j = i + len - 1;
                long long s = prefix[j + 1] - prefix[i];
                dp[i][j] = s - min(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        
        printf("%lld\n", dp[0][N - 1]);
    }
    
    return 0;
}