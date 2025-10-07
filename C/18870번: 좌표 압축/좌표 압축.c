/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 18870                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/18870                          #+#        #+#      #+#    */
/*   Solved: 2025/10/07 12:33:55 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp_int_asc(const void *x, const void *y) {
    int a = *(const int*)x, b = *(const int*)y;
    return (a > b) - (a < b);
}

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;

    int *a = (int*)malloc(sizeof(int)*N);
    for (int i = 0; i < N; ++i) scanf("%d", &a[i]);

    int *b = (int*)malloc(sizeof(int)*N);
    memcpy(b, a, sizeof(int)*N);
    qsort(b, N, sizeof(int), cmp_int_asc);

    int *u = (int*)malloc(sizeof(int)*N);
    int m = 0;
    for (int i = 0; i < N; ++i) {
        if (i == 0 || b[i] != b[i-1]) u[m++] = b[i];
    }

    for (int i = 0; i < N; ++i) {
        int *p = (int*)bsearch(&a[i], u, m, sizeof(int), cmp_int_asc);
        int rank = (int)(p - u);
        printf("%d%c", rank, (i+1==N)?'\n':' ');
    }

    free(a); free(b); free(u);
    return 0;
}