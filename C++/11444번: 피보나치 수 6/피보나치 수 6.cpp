/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11444                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11444                          #+#        #+#      #+#    */
/*   Solved: 2026/01/03 14:47:10 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1000000007;

typedef vector<vector<long long>> Matrix;

// 행렬 곱셈
Matrix multiply(const Matrix& A, const Matrix& B) {
    Matrix result(2, vector<long long>(2, 0));

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                result[i][j] += A[i][k] * B[k][j];
                result[i][j] %= MOD;
            }
        }
    }

    return result;
}

// 행렬 거듭제곱
Matrix matrix_power(Matrix base, long long exp) {
    // 단위 행렬로 초기화
    Matrix result = {{1, 0}, {0, 1}};

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

    Matrix base = {{1, 1}, {1, 0}};
    Matrix result = matrix_power(base, n);

    return result[1][0];  // F(n)의 위치
}

int main() {
    long long n;
    cin >> n;

    cout << fibonacci(n) << "\n";

    return 0;
}