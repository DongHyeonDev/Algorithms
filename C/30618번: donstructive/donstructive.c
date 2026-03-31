/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 30618                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/30618                          #+#        #+#      #+#    */
/*   Solved: 2026/03/31 16:25:41 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 200001

int positions[MAX_N];
int result[MAX_N];
int N;

int cmp(const void* a, const void* b) {
    int pa = *(int*)a, pb = *(int*)b;
    long long ca = (long long)pa * (N - pa + 1);
    long long cb = (long long)pb * (N - pb + 1);
    return cb > ca ? 1 : cb < ca ? -1 : 0;
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) positions[i-1] = i;
    qsort(positions, N, sizeof(int), cmp);
    for (int i = 0; i < N; i++) result[positions[i]] = N - i;
    for (int i = 1; i <= N; i++) {
        printf("%d", result[i]);
        if (i < N) printf(" ");
    }
    printf("\n");
    return 0;
}