/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9252                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9252                           #+#        #+#      #+#    */
/*   Solved: 2026/02/26 14:14:20 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string A, B;
    cin >> A >> B;
    int N = A.size(), M = B.size();
    
    // dp[i][j] = A[0..i-1], B[0..j-1]의 LCS 길이
    vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (A[i-1] == B[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    cout << dp[N][M] << "\n";
    
    // 역추적: dp[N][M]에서 출발
    if (dp[N][M] > 0) {
        string result;
        int i = N, j = M;
        while (i > 0 && j > 0) {
            if (A[i-1] == B[j-1]) {
                result += A[i-1];  // LCS 문자 수집 (역순)
                i--; j--;
            } else if (dp[i-1][j] > dp[i][j-1]) {
                i--;
            } else {
                j--;
            }
        }
        reverse(result.begin(), result.end());
        cout << result << "\n";
    }
    
    return 0;
}