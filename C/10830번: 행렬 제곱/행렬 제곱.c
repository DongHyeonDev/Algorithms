/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10830                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10830                          #+#        #+#      #+#    */
/*   Solved: 2026/01/02 10:15:46 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

#define MOD 1000

int N;

// 행렬 곱셈
void matrix_multiply(int A[5][5], int B[5][5], int result[5][5]) {
    int temp[5][5] = {0};

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                temp[i][j] += A[i][k] * B[k][j];
                temp[i][j] %= MOD;
            }
        }
    }

    // 결과 복사
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = temp[i][j];
        }
    }
}

// 행렬 거듭제곱 (분할 정복)
void matrix_power(int A[5][5], long long B, int result[5][5]) {
    // 단위 행렬로 초기화
    int temp[5][5];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result[i][j] = (i == j) ? 1 : 0;
            temp[i][j] = A[i][j];
        }
    }

    while (B > 0) {
        if (B % 2 == 1) {
            matrix_multiply(result, temp, result);
        }
        matrix_multiply(temp, temp, temp);
        B /= 2;
    }
}

int main() {
    long long B;
    int A[5][5], result[5][5];

    scanf("%d %lld", &N, &B);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &A[i][j]);
            A[i][j] %= MOD;
        }
    }

    matrix_power(A, B, result);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d", result[i][j]);
            if (j < N - 1) printf(" ");
        }
        printf("\n");
    }

    return 0;
}