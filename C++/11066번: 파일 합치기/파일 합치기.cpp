/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11066                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11066                          #+#        #+#      #+#    */
/*   Solved: 2026/02/16 10:58:36 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define INF 1000000000

int files[501];
int sum[501];      // 누적합
int dp[501][501];  // dp[i][j] = i번째부터 j번째까지 합치는 최소 비용

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int K;
        cin >> K;
        
        for (int i = 1; i <= K; i++) {
            cin >> files[i];
        }
        
        // 누적합 계산
        sum[0] = 0;
        for (int i = 1; i <= K; i++) {
            sum[i] = sum[i - 1] + files[i];
        }
        
        // DP 초기화
        memset(dp, 0, sizeof(dp));
        
        // 길이별로 DP
        for (int len = 2; len <= K; len++) {
            for (int i = 1; i + len - 1 <= K; i++) {
                int j = i + len - 1;
                dp[i][j] = INF;
                
                // i부터 j까지 합치는 최소 비용
                for (int k = i; k < j; k++) {
                    int cost = dp[i][k] + dp[k + 1][j] + (sum[j] - sum[i - 1]);
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }
        
        cout << dp[1][K] << "\n";
    }
    
    return 0;
}