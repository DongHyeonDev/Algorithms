/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 25184                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/25184                          #+#        #+#      #+#    */
/*   Solved: 2026/04/04 13:52:30 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int main() {
    int N; scanf("%d", &N);
    int half = N / 2;
    int lo = 1, hi = half + 1;
    int first = 1;
    while (hi <= N || lo <= half) {
        if (hi <= N) {
            if (!first) printf(" ");
            printf("%d", hi++); first = 0;
        }
        if (lo <= half) {
            if (!first) printf(" ");
            printf("%d", lo++); first = 0;
        }
    }
    printf("\n");
    return 0;
}