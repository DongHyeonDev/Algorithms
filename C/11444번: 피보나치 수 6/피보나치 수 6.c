/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11444                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11444                          #+#        #+#      #+#    */
/*   Solved: 2026/01/03 14:47:02 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

#define MOD 1000000007

typedef struct {
    long long m[2][2];
} Matrix;

// 행렬 곱셈
Matrix multiply(Matrix a, Matrix b) {
    Matrix result;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result.m[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                result.m[i][j] += a.m[i][k] * b.m[k][j];
                result.m[i][j] %= MOD;
            }
        }
    }

    return result;
}

// 행렬 거듭제곱
Matrix matrix_power(Matrix base, long long exp) {
    Matrix result;

    // 단위 행렬로 초기화
    result.m[0][0] = result.m[1][1] = 1;
    result.m[0][1] = result.m[1][0] = 0;

    while (exp > 0) {
        if (exp % 2 == 1) {
            result = multiply(result, base);
        }
        base = multiply(base, base);
        exp /= 2;
    }

    return result;
}

long long fibonacci(long long n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    Matrix base;
    base.m[0][0] = base.m[0][1] = base.m[1][0] = 1;
    base.m[1][1] = 0;

    Matrix result = matrix_power(base, n);

    return result.m[1][0];  // F(n)의 위치
}

int main() {
    long long n;
    scanf("%lld", &n);

    printf("%lld\n", fibonacci(n));

    return 0;
}