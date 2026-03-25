/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 6549                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/6549                           #+#        #+#      #+#    */
/*   Solved: 2026/03/25 17:19:47 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

#define MAX_N 100001

long long h[MAX_N];
int stack[MAX_N];

int main() {
    int n;
    while (scanf("%d", &n) && n != 0) {
        for (int i = 0; i < n; i++) scanf("%lld", &h[i]);
        
        int top = -1;
        long long ans = 0;
        
        for (int i = 0; i <= n; i++) {
            long long cur = (i == n) ? 0 : h[i];
            while (top >= 0 && h[stack[top]] > cur) {
                long long height = h[stack[top--]];
                long long width = (top < 0) ? i : i - stack[top] - 1;
                long long area = height * width;
                if (area > ans) ans = area;
            }
            stack[++top] = i;
        }
        
        printf("%lld\n", ans);
    }
    return 0;
}