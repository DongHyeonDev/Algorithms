/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1929                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1929                           #+#        #+#      #+#    */
/*   Solved: 2025/10/21 10:43:23 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int main() {
    int M, N;
    if (scanf("%d %d", &M, &N) != 2) return 0;

    char *is_composite = (char *)calloc(N + 1, sizeof(char));
    if (!is_composite) return 0;

    is_composite[0] = 1;
    if (N >= 1) is_composite[1] = 1;

    for (int p = 2; p * p <= N; ++p) {
        if (!is_composite[p]) {
            for (int q = p * p; q <= N; q += p) {
                is_composite[q] = 1;
            }
        }
    }

    for (int x = M; x <= N; ++x) {
        if (!is_composite[x]) {
            printf("%d\n", x);
        }
    }

    free(is_composite);
    return 0;
}