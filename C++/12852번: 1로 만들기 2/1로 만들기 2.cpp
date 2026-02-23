/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 12852                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/12852                          #+#        #+#      #+#    */
/*   Solved: 2026/02/23 11:33:07 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> dp(N + 1, 1e9);
    vector<int> from(N + 1, 0);  // from[i] = i에서 이동한 다음 값 (역추적용)
    
    dp[1] = 0;
    for (int i = 2; i <= N; i++) {
        // 연산 3: 1 빼기
        dp[i] = dp[i - 1] + 1;
        from[i] = i - 1;
        
        // 연산 2: 2로 나누기
        if (i % 2 == 0 && dp[i / 2] + 1 < dp[i]) {
            dp[i] = dp[i / 2] + 1;
            from[i] = i / 2;
        }
        
        // 연산 1: 3으로 나누기
        if (i % 3 == 0 && dp[i / 3] + 1 < dp[i]) {
            dp[i] = dp[i / 3] + 1;
            from[i] = i / 3;
        }
    }
    
    cout << dp[N] << "\n";

    // 역추적: N → 1 방향으로 from을 따라가며 수집
    vector<int> path;
    int cur = N;
    while (cur != 0) {
        path.push_back(cur);
        cur = from[cur];
    }
    for (int i = 0; i < (int)path.size(); i++) {
        cout << path[i];
        if (i + 1 < (int)path.size()) cout << " ";
    }
    cout << "\n";
    
    return 0;
}