/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9252                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9252                           #+#        #+#      #+#    */
/*   Solved: 2026/02/26 14:14:13 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

#define MAX 1001

char A[MAX], B[MAX];
int dp[MAX][MAX];
char result[MAX];

int max(int a, int b) { return a > b ? a : b; }

int main() {
    scanf("%s %s", A, B);
    int N = strlen(A), M = strlen(B);
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (A[i-1] == B[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    printf("%d\n", dp[N][M]);
    
    // 역추적
    if (dp[N][M] > 0) {
        int i = N, j = M, len = 0;
        while (i > 0 && j > 0) {
            if (A[i-1] == B[j-1]) {
                result[len++] = A[i-1];
                i--; j--;
            } else if (dp[i-1][j] > dp[i][j-1]) {
                i--;
            } else {
                j--;
            }
        }
        // 역순 출력
        for (int k = len - 1; k >= 0; k--) printf("%c", result[k]);
        printf("\n");
    }
    
    return 0;
}