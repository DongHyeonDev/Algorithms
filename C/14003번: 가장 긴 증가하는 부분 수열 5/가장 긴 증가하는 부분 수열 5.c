/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 14003                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/14003                          #+#        #+#      #+#    */
/*   Solved: 2026/02/25 12:11:47 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000001

int A[MAX_N];
int tails[MAX_N];   // tails[k] = 길이 k+1 LIS의 최솟값
int idx[MAX_N];     // idx[k] = tails[k]에 해당하는 원소 인덱스
int dp[MAX_N];      // dp[i] = i에서 끝나는 LIS 길이
int from[MAX_N];    // from[i] = 이전 원소 인덱스
int path[MAX_N];

// lower_bound: tails[0..len-1]에서 val 이상인 첫 번째 위치
int lowerBound(int len, int val) {
    int lo = 0, hi = len;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (tails[mid] < val) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);
    
    int tailsLen = 0;
    
    for (int i = 0; i < N; i++) {
        int pos = lowerBound(tailsLen, A[i]);
        
        tails[pos] = A[i];
        idx[pos] = i;
        if (pos == tailsLen) tailsLen++;
        
        dp[i] = pos + 1;
        from[i] = (pos > 0) ? idx[pos - 1] : -1;
    }
    
    // LIS 끝 인덱스 탐색
    int maxLen = tailsLen, endIdx = -1;
    for (int i = N - 1; i >= 0; i--) {
        if (dp[i] == maxLen) { endIdx = i; break; }
    }
    
    printf("%d\n", maxLen);
    
    // 역추적
    int len = 0, cur = endIdx;
    while (cur != -1) {
        path[len++] = A[cur];
        cur = from[cur];
    }
    for (int i = len - 1; i >= 0; i--) {
        printf("%d", path[i]);
        if (i > 0) printf(" ");
    }
    printf("\n");
    
    return 0;
}