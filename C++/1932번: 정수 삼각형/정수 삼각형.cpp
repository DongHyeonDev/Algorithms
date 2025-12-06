/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1932                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1932                           #+#        #+#      #+#    */
/*   Solved: 2025/12/06 14:55:04 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> triangle(n);

    // 삼각형 입력
    for (int i = 0; i < n; i++) {
        triangle[i].resize(i + 1);
        for (int j = 0; j <= i; j++) {
            cin >> triangle[i][j];
        }
    }

    // dp[i][j] = (i, j) 위치까지의 최대 합
    vector<vector<int>> dp(n);

    // 초기값: 맨 위
    dp[0].resize(1);
    dp[0][0] = triangle[0][0];

    // DP 계산
    for (int i = 1; i < n; i++) {
        dp[i].resize(i + 1);
        for (int j = 0; j <= i; j++) {
            // 가장 왼쪽 (j=0)
            if (j == 0) {
                dp[i][j] = dp[i-1][j] + triangle[i][j];
            }
            // 가장 오른쪽 (j=i)
            else if (j == i) {
                dp[i][j] = dp[i-1][j-1] + triangle[i][j];
            }
            // 중간 위치
            else {
                dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
            }
        }
    }

    // 마지막 행에서 최댓값 찾기
    int result = *max_element(dp[n-1].begin(), dp[n-1].end());

    cout << result << "\n";

    return 0;
}