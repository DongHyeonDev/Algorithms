/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 14003                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/14003                          #+#        #+#      #+#    */
/*   Solved: 2026/02/25 12:11:52 by dhkim0206     ###          ###   ##.kr    */
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
    
    vector<int> tails;        // tails[k] = 길이 k+1 LIS의 최솟값
    vector<int> tailIdx;      // tailIdx[k] = tails[k]의 원본 인덱스
    vector<int> dp(N);        // dp[i] = i에서 끝나는 LIS 길이
    vector<int> from(N, -1); // from[i] = 이전 원소 인덱스
    
    for (int i = 0; i < N; i++) {
        // lower_bound: A[i] 이상인 첫 번째 위치
        int pos = (int)(lower_bound(tails.begin(), tails.end(), A[i]) - tails.begin());
        
        if (pos == (int)tails.size()) {
            tails.push_back(A[i]);
            tailIdx.push_back(i);
        } else {
            tails[pos] = A[i];
            tailIdx[pos] = i;
        }
        
        dp[i] = pos + 1;
        from[i] = (pos > 0) ? tailIdx[pos - 1] : -1;
    }
    
    // LIS 끝 인덱스 탐색
    int maxLen = (int)tails.size(), endIdx = -1;
    for (int i = N - 1; i >= 0; i--) {
        if (dp[i] == maxLen) { endIdx = i; break; }
    }
    
    cout << maxLen << "\n";
    
    // 역추적
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