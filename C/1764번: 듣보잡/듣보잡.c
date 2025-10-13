/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1764                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1764                           #+#        #+#      #+#    */
/*   Solved: 2025/10/13 07:35:59 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp_str(const void* a, const void* b) {
    const char* const* sa = (const char* const*)a;
    const char* const* sb = (const char* const*)b;
    return strcmp(*sa, *sb);
}

int main() {
    int N, M;
    if (scanf("%d %d", &N, &M) != 2) return 0;

    char **A = (char**)malloc(sizeof(char*) * N);
    char **B = (char**)malloc(sizeof(char*) * M);
    if (!A || !B) return 0;

    char buf[21];
    for (int i = 0; i < N; ++i) {
        scanf("%20s", buf);
        A[i] = (char*)malloc(strlen(buf) + 1);
        strcpy(A[i], buf);
    }
    for (int i = 0; i < M; ++i) {
        scanf("%20s", buf);
        B[i] = (char*)malloc(strlen(buf) + 1);
        strcpy(B[i], buf);
    }

    qsort(A, N, sizeof(char*), cmp_str);
    qsort(B, M, sizeof(char*), cmp_str);

    char **ans = (char**)malloc(sizeof(char*) * (N < M ? N : M));
    int i = 0, j = 0, k = 0;
    while (i < N && j < M) {
        int cmp = strcmp(A[i], B[j]);
        if (cmp == 0) {
            ans[k] = A[i];
            ++k; ++i; ++j;
        } else if (cmp < 0) {
            ++i;
        } else {
            ++j;
        }
    }

    printf("%d\n", k);
    for (int t = 0; t < k; ++t) {
        printf("%s\n", ans[t]);
    }

    for (int t = 0; t < N; ++t) free(A[t]);
    for (int t = 0; t < M; ++t) free(B[t]);
    free(A); free(B); free(ans);
    return 0;
}