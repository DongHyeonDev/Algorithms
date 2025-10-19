/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2485                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2485                           #+#        #+#      #+#    */
/*   Solved: 2025/10/19 14:57:18 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a >= 0 ? a : -a;
}

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;

    int *x = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; ++i) scanf("%d", &x[i]);

    int g = 0;
    for (int i = 0; i < N - 1; ++i) {
        int d = x[i + 1] - x[i];
        g = (i == 0) ? d : gcd(g, d);
    }

    int add = 0;
    for (int i = 0; i < N - 1; ++i) {
        int d = x[i + 1] - x[i];
        add += d / g - 1;
    }

    printf("%d\n", add);
    free(x);
    return 0;
}