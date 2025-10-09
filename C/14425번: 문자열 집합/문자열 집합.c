/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 14425                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/14425                          #+#        #+#      #+#    */
/*   Solved: 2025/10/09 10:57:31 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp_str_ptr(const void *a, const void *b) {
    const char *sa = *(const char* const*)a;
    const char *sb = *(const char* const*)b;
    return strcmp(sa, sb);
}

int main() {
    int N, M;
    if (scanf("%d %d", &N, &M) != 2) return 0;

    char **S = (char**)malloc(sizeof(char*) * N);
    char buf[501];

    for (int i = 0; i < N; ++i) {
        scanf("%500s", buf);
        S[i] = (char*)malloc(strlen(buf) + 1);
        strcpy(S[i], buf);
    }

    qsort(S, N, sizeof(char*), cmp_str_ptr);

    int count = 0;
    for (int i = 0; i < M; ++i) {
        scanf("%500s", buf);
        char *key = buf;
        void *p = bsearch(&key, S, N, sizeof(char*), cmp_str_ptr);
        if (p) ++count;
    }

    printf("%d\n", count);

    for (int i = 0; i < N; ++i) free(S[i]);
    free(S);
    return 0;
}