/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 5639                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/5639                           #+#        #+#      #+#    */
/*   Solved: 2026/03/09 14:21:26 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

#define MAX_N 10001

int pre[MAX_N], n = 0;
int result[MAX_N], resLen = 0;

void solve(int l, int r) {
    if (l > r) return;
    
    int root = pre[l];
    
    // root보다 큰 첫 번째 인덱스 탐색
    int mid = r + 1;
    for (int i = l + 1; i <= r; i++) {
        if (pre[i] > root) { mid = i; break; }
    }
    
    solve(l + 1, mid - 1); // 왼쪽 서브트리
    solve(mid, r);          // 오른쪽 서브트리
    result[resLen++] = root; // 후위: 루트 마지막
}

int main() {
    while (scanf("%d", &pre[n]) == 1) n++;
    
    if (n > 0) {
        solve(0, n - 1);
        for (int i = 0; i < resLen; i++) printf("%d\n", result[i]);
    }
    
    return 0;
}