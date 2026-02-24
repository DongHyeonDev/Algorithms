/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 14002                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/14002                          #+#        #+#      #+#    */
/*   Solved: 2026/02/24 11:33:18 by dhkim0206     ###          ###   ##.kr    */
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
    for (int i = 0; i < N; i++) cin >> A[i];
    
    vector<int> dp(N, 1);    // dp[i] = i에서 끝나는 LIS 길이
    vector<int> from(N, -1); // from[i] = LIS에서 i 이전 인덱스
    
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (A[j] < A[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                from[i] = j;
            }
        }
    }
    
    // LIS 길이 및 끝 인덱스 탐색
    int maxLen = *max_element(dp.begin(), dp.end());
    // 동일 길이가 여럿이면 마지막 인덱스 선택 (아무거나 가능)
    int endIdx = (int)(find(dp.rbegin(), dp.rend(), maxLen) - dp.rbegin());
    endIdx = N - 1 - endIdx;
    
    cout << maxLen << "\n";
    
    // 역추적: endIdx → ... → -1
    vector<int> path;
    int cur = endIdx;
    while (cur != -1) {
        path.push_back(A[cur]);
        cur = from[cur];
    }
    reverse(path.begin(), path.end());
    for (int i = 0; i < (int)path.size(); i++) {
        cout << path[i];
        if (i + 1 < (int)path.size()) cout << " ";
    }
    cout << "\n";
    
    return 0;
}