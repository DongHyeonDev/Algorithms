/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 13018                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/13018                          #+#        #+#      #+#    */
/*   Solved: 2026/04/10 12:24:30 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    if (k > n-1) { printf("Impossible\n"); return 0; }
    
    int A[100001];
    for (int i = 1; i <= n; i++) A[i] = i;
    
    int need = (n-1) - k;
    int startPair = 2;
    
    if (need % 2 == 1) {
        // (1,2) 교환: -1
        int tmp = A[1]; A[1] = A[2]; A[2] = tmp;
        need--;
        startPair = 4;
    }
    
    int pos = startPair;
    while (need > 0) {
        int tmp = A[pos]; A[pos] = A[pos+1]; A[pos+1] = tmp;
        need -= 2; pos += 2;
    }
    
    for (int i = 1; i <= n; i++) {
        printf("%d", A[i]);
        if (i < n) printf(" ");
    }
    printf("\n");
    return 0;
}