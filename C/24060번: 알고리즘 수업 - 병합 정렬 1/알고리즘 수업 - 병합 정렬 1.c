/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 24060                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/24060                          #+#        #+#      #+#    */
/*   Solved: 2025/11/18 11:46:00 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int *A;
int *tmp;
int save_count;
int K;
int result;

void merge(int p, int q, int r) {
    int i = p;
    int j = q + 1;
    int t = 0;

    while (i <= q && j <= r) {
        if (A[i] <= A[j]) {
            tmp[t++] = A[i++];
        } else {
            tmp[t++] = A[j++];
        }
    }

    while (i <= q) {
        tmp[t++] = A[i++];
    }

    while (j <= r) {
        tmp[t++] = A[j++];
    }

    i = p;
    t = 0;
    while (i <= r) {
        A[i++] = tmp[t++];
        save_count++;

        if (save_count == K) {
            result = A[i - 1];
        }
    }
}

void merge_sort(int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        merge_sort(p, q);
        merge_sort(q + 1, r);
        merge(p, q, r);
    }
}

int main() {
    int N;
    scanf("%d %d", &N, &K);

    A = (int*)malloc(N * sizeof(int));
    tmp = (int*)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    save_count = 0;
    result = -1;

    merge_sort(0, N - 1);

    printf("%d\n", result);

    free(A);
    free(tmp);

    return 0;
}