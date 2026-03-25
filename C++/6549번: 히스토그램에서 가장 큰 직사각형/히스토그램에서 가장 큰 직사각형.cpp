/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 6549                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/6549                           #+#        #+#      #+#    */
/*   Solved: 2026/03/25 17:19:54 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<long long> h(n);
        for (int i = 0; i < n; i++) cin >> h[i];
        
        stack<int> st;  // 단조 증가 스택 (인덱스)
        long long ans = 0;
        
        for (int i = 0; i <= n; i++) {
            long long cur = (i == n) ? 0 : h[i];
            
            // 현재 높이보다 높은 막대들 처리
            while (!st.empty() && h[st.top()] > cur) {
                long long height = h[st.top()]; st.pop();
                // 너비: 스택이 비었으면 0부터, 아니면 이전 인덱스+1부터 i-1까지
                long long width = st.empty() ? i : i - st.top() - 1;
                ans = max(ans, height * width);
            }
            st.push(i);
        }
        
        cout << ans << "\n";
    }
    return 0;
}