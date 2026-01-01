/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2740                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2740                           #+#        #+#      #+#    */
/*   Solved: 2026/01/01 12:48:09 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int main() {
    int N, M, K;
    int A[100][100], B[100][100], C[100][100];

    // 행렬 A 입력
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // 행렬 B 입력
    scanf("%d %d", &M, &K);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // 행렬 곱셈: C = A × B
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            C[i][j] = 0;
            for (int k = 0; k < M; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // 결과 출력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            printf("%d", C[i][j]);
            if (j < K - 1) printf(" ");
        }
        printf("\n");
    }

    return 0;
}