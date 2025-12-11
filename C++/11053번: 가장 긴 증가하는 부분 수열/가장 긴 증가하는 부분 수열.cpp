/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11053                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11053                          #+#        #+#      #+#    */
/*   Solved: 2025/12/11 13:38:36 by dhkim0206     ###          ###   ##.kr    */
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

    // dp[i] = i번째 원소를 마지막으로 하는 LIS의 길이
    vector<int> dp(N, 1);  // 초기값 1

    // DP 계산
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            // A[j] < A[i]이면 A[j] 뒤에 A[i]를 붙일 수 있음
            if (A[j] < A[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // 최댓값 찾기
    int result = *max_element(dp.begin(), dp.end());

    cout << result << "\n";

    return 0;
}