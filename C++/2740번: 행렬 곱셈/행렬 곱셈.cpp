/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2740                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2740                           #+#        #+#      #+#    */
/*   Solved: 2026/01/01 12:48:15 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M, K;

    // 행렬 A 입력
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }

    // 행렬 B 입력
    cin >> M >> K;
    vector<vector<int>> B(M, vector<int>(K));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            cin >> B[i][j];
        }
    }

    // 행렬 곱셈: C = A × B
    vector<vector<int>> C(N, vector<int>(K, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            for (int k = 0; k < M; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // 결과 출력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            cout << C[i][j];
            if (j < K - 1) cout << " ";
        }
        cout << "\n";
    }

    return 0;
}