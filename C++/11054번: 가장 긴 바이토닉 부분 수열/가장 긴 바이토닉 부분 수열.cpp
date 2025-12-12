/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11054                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11054                          #+#        #+#      #+#    */
/*   Solved: 2025/12/12 13:59:13 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // increase[i] = i로 끝나는 증가 부분 수열의 길이 (LIS)
    vector<int> increase(N, 1);
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (A[j] < A[i]) {
                increase[i] = max(increase[i], increase[j] + 1);
            }
        }
    }

    // decrease[i] = i에서 시작하는 감소 부분 수열의 길이 (LDS)
    vector<int> decrease(N, 1);
    for (int i = N - 2; i >= 0; i--) {
        for (int j = i + 1; j < N; j++) {
            if (A[i] > A[j]) {
                decrease[i] = max(decrease[i], decrease[j] + 1);
            }
        }
    }

    // 바이토닉 수열의 최대 길이
    // i를 정점으로 하는 바이토닉: increase[i] + decrease[i] - 1
    int result = 0;
    for (int i = 0; i < N; i++) {
        int bitonic = increase[i] + decrease[i] - 1;
        result = max(result, bitonic);
    }

    cout << result << "\n";

    return 0;
}