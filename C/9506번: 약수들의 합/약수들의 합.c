/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9506                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9506                           #+#        #+#      #+#    */
/*   Solved: 2025/08/11 16:56:55 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int main() {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == -1) break;

        int sum = 0;
        for (int i = 1; i <= n / 2; i++) {
            if (n % i == 0) sum += i;
        }

        if (sum == n) {
            printf("%d = ", n);
            for (int i = 1; i <= n / 2; i++) {
                if (n % i == 0) {
                    printf("%d", i);
                    if (i != n / 2) printf(" + ");
                }
            }
            printf("\n");
        } else {
            printf("%d is NOT perfect.\n", n);
        }
    }
    return 0;
}