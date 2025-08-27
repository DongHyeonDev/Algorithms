/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2581                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2581                           #+#        #+#      #+#    */
/*   Solved: 2025/08/27 22:35:24 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdbool.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int sum = 0;
    int min_prime = -1;

    for (int num = m; num <= n; ++num) {
        if (num < 2) continue;
        bool is_prime = true;
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) {
            sum += num;
            if (min_prime == -1) {
                min_prime = num;
            }
        }
    }

    if (sum == 0) {
        printf("-1\n");
    } else {
        printf("%d\n", sum);
        printf("%d\n", min_prime);
    }

    return 0;
}