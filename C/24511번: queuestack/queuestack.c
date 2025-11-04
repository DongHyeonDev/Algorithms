/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 24511                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/24511                          #+#        #+#      #+#    */
/*   Solved: 2025/11/04 12:27:49 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M;
    scanf("%d", &N);

    int *A = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    int *B = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &B[i]);
    }
    scanf("%d", &M);

    int capacity = N + M;
    int *deque = (int *)malloc(capacity * sizeof(int));
    int start = M;
    int end = M;

    for (int i = 0; i < N; i++) {
        if (A[i] == 0) {
            deque[end++] = B[i];
        }
    }

    for (int i = 0; i < M; i++) {
        int x;
        scanf("%d", &x);

        if (start == end) {
            printf("%d", x);
        } else {
            printf("%d", deque[--end]);
            deque[--start] = x;
        }

        if (i < M - 1) printf(" ");
    }
    printf("\n");

    free(A);
    free(B);
    free(deque);

    return 0;
}