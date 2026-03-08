/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2263                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2263                           #+#        #+#      #+#    */
/*   Solved: 2026/03/08 13:13:15 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int n;
vector<int> ino, post, result;
unordered_map<int,int> inoIdx;  // 값 → 인오더 인덱스

void solve(int inL, int inR, int postL, int postR) {
    if (inL > inR) return;
    
    int root = post[postR];       // 포스트오더 마지막 = 루트
    result.push_back(root);       // 프리오더: 루트 먼저
    
    int mid = inoIdx[root];       // 인오더에서 루트 위치
    int leftSize = mid - inL;     // 왼쪽 서브트리 크기
    
    // 왼쪽 서브트리: inorder[inL..mid-1], postorder[postL..postL+leftSize-1]
    solve(inL, mid - 1, postL, postL + leftSize - 1);
    // 오른쪽 서브트리: inorder[mid+1..inR], postorder[postL+leftSize..postR-1]
    solve(mid + 1, inR, postL + leftSize, postR - 1);
}

int main() {
    cin >> n;
    ino.resize(n); post.resize(n);
    result.reserve(n);
    
    for (int i = 0; i < n; i++) {
        cin >> ino[i];
        inoIdx[ino[i]] = i;   // 값 → 인덱스 O(1) 매핑
    }
    for (int i = 0; i < n; i++) cin >> post[i];
    
    solve(0, n - 1, 0, n - 1);
    
    for (int i = 0; i < n; i++) {
        cout << result[i];
        if (i < n - 1) cout << " ";
    }
    cout << "\n";
    
    return 0;
}