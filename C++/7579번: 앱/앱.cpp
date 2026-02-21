/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 7579                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/7579                           #+#        #+#      #+#    */
/*   Solved: 2026/02/21 16:26:46 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<int> m(N), c(N);
    for (int i = 0; i < N; i++) cin >> m[i];
    for (int i = 0; i < N; i++) cin >> c[i];
    
    int maxCost = 0;
    for (int i = 0; i < N; i++) maxCost += c[i];
    
    // dp[j] = 비용 j를 사용했을 때 확보 가능한 최대 메모리
    vector<long long> dp(maxCost + 1, 0);
    
    for (int i = 0; i < N; i++) {
        // 0/1 knapsack: 역순 순회 (중복 선택 방지)
        for (int j = maxCost; j >= c[i]; j--) {
            dp[j] = max(dp[j], dp[j - c[i]] + (long long)m[i]);
        }
    }
    
    // 최소 비용 탐색
    for (int cost = 0; cost <= maxCost; cost++) {
        if (dp[cost] >= M) {
            cout << cost << "\n";
            return 0;
        }
    }
    
    return 0;
}