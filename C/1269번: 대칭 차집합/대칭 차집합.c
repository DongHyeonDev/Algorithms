/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1269                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1269                           #+#        #+#      #+#    */
/*   Solved: 2025/10/14 17:26:22 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int cmp_int(const void *a, const void *b) {
    int x = *(const int*)a, y = *(const int*)b;
    return (x > y) - (x < y);
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    int *A = (int*)malloc(sizeof(int) * n);
    int *B = (int*)malloc(sizeof(int) * m);
    if (!A || !B) return 0;

    for (int i = 0; i < n; ++i) scanf("%d", &A[i]);
    for (int j = 0; j < m; ++j) scanf("%d", &B[j]);

    qsort(A, n, sizeof(int), cmp_int);
    qsort(B, m, sizeof(int), cmp_int);

    int i = 0, j = 0, common = 0;
    while (i < n && j < m) {
        if (A[i] == B[j]) { ++common; ++i; ++j; }
        else if (A[i] < B[j]) { ++i; }
        else { ++j; }
    }

    long long ans = (long long)n + (long long)m - 2LL * common;
    printf("%lld\n", ans);

    free(A);
    free(B);
    return 0;
}