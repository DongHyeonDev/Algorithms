/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2263                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2263                           #+#        #+#      #+#    */
/*   Solved: 2026/03/08 13:13:11 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

#define MAX_N 100001

int ino[MAX_N], post[MAX_N];
int inoIdx[MAX_N];   // 값 → 인오더 인덱스
int result[MAX_N];
int resLen = 0;

void solve(int inL, int inR, int postL, int postR) {
    if (inL > inR) return;
    
    int root = post[postR];         // 포스트오더 마지막 = 루트
    result[resLen++] = root;        // 프리오더 수집
    
    int mid = inoIdx[root];         // 인오더에서 루트 위치
    int leftSize = mid - inL;
    
    // 왼쪽 서브트리
    solve(inL, mid - 1, postL, postL + leftSize - 1);
    // 오른쪽 서브트리
    solve(mid + 1, inR, postL + leftSize, postR - 1);
}

int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &ino[i]);
        inoIdx[ino[i]] = i;   // 값 → 인덱스 매핑
    }
    for (int i = 0; i < n; i++) scanf("%d", &post[i]);
    
    solve(0, n - 1, 0, n - 1);
    
    for (int i = 0; i < resLen; i++) {
        printf("%d", result[i]);
        if (i < resLen - 1) printf(" ");
    }
    printf("\n");
    
    return 0;
}