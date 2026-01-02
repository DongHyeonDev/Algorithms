/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10830                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10830                          #+#        #+#      #+#    */
/*   Solved: 2026/01/02 10:15:51 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000;
typedef vector<vector<long long>> Matrix;

int N;

// 행렬 곱셈
Matrix multiply(const Matrix& A, const Matrix& B) {
    Matrix result(N, vector<long long>(N, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                result[i][j] += A[i][k] * B[k][j];
                result[i][j] %= MOD;
            }
        }
    }

    return result;
}

// 행렬 거듭제곱 (분할 정복)
Matrix matrix_power(Matrix A, long long B) {
    // 단위 행렬로 초기화
    Matrix result(N, vector<long long>(N, 0));
    for (int i = 0; i < N; i++) {
        result[i][i] = 1;
    }

    while (B > 0) {
        if (B % 2 == 1) {
            result = multiply(result, A);
        }
        A = multiply(A, A);
        B /= 2;
    }

    return result;
}

int main() {
    long long B;
    cin >> N >> B;

    Matrix A(N, vector<long long>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
            A[i][j] %= MOD;
        }
    }

    Matrix result = matrix_power(A, B);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << result[i][j];
            if (j < N - 1) cout << " ";
        }
        cout << "\n";
    }

    return 0;
}