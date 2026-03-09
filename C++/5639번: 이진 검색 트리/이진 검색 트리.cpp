/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 5639                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/5639                           #+#        #+#      #+#    */
/*   Solved: 2026/03/09 14:21:33 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
using namespace std;

vector<int> pre, result;

void solve(int l, int r) {
    if (l > r) return;
    
    int root = pre[l];
    
    // BST 특성: root보다 큰 첫 번째 인덱스 = 오른쪽 서브트리 시작
    int mid = r + 1;
    for (int i = l + 1; i <= r; i++) {
        if (pre[i] > root) { mid = i; break; }
    }
    
    solve(l + 1, mid - 1);  // 왼쪽 서브트리 (pre[l] 미만)
    solve(mid, r);           // 오른쪽 서브트리 (pre[l] 초과)
    result.push_back(root);  // 후위: 루트 마지막 수집
}

int main() {
    int v;
    while (cin >> v) pre.push_back(v);
    
    if (!pre.empty()) {
        result.reserve(pre.size());
        solve(0, (int)pre.size() - 1);
        for (int x : result) cout << x << "\n";
    }
    
    return 0;
}