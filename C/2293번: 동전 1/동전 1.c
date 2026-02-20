/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2293                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2293                           #+#        #+#      #+#    */
/*   Solved: 2026/02/20 11:02:42 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

int n, k;
int coins[100];
long long dp[10001];

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &coins[i]);
    
    dp[0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = coins[i]; j <= k; j++)
            dp[j] += dp[j - coins[i]];
    
    printf("%lld\n", dp[k]);
    return 0;
}