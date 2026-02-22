/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11062                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11062                          #+#        #+#      #+#    */
/*   Solved: 2026/02/22 16:25:09 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        
        vector<int> cards(N);
        vector<long long> prefix(N + 1, 0);
        
        for (int i = 0; i < N; i++) {
            cin >> cards[i];
            prefix[i + 1] = prefix[i] + cards[i];
        }
        
        auto rangeSum = [&](int i, int j) {
            return prefix[j + 1] - prefix[i];
        };
        
        // dp[i][j] = 현재 플레이어가 [i..j]에서 얻는 최대 점수
        vector<vector<long long>> dp(N, vector<long long>(N, 0));
        
        // 기저: 카드 1장
        for (int i = 0; i < N; i++) dp[i][i] = cards[i];
        
        for (int len = 2; len <= N; len++) {
            for (int i = 0; i + len - 1 < N; i++) {
                int j = i + len - 1;
                long long s = rangeSum(i, j);
                dp[i][j] = s - min(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        
        cout << dp[0][N - 1] << "\n";
    }
    
    return 0;
}