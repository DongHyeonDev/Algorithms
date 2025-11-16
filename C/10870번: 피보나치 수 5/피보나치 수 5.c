/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10870                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10870                          #+#        #+#      #+#    */
/*   Solved: 2025/11/16 14:23:22 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

long long memo[21];

long long fibonacci_memo(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    if (memo[n] != -1) {
        return memo[n];
    }

    memo[n] = fibonacci_memo(n - 1) + fibonacci_memo(n - 2);
    return memo[n];
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i <= 20; i++) {
        memo[i] = -1;
    }

    printf("%lld\n", fibonacci_memo(n));

    return 0;
}