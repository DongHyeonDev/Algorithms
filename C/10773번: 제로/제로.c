/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10773                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10773                          #+#        #+#      #+#    */
/*   Solved: 2025/10/26 14:54:12 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#define MAX 100000

int main() {
    int K, x, stk[MAX], top = 0;
    long long sum = 0;
    if (scanf("%d", &K) != 1) return 0;

    for (int i = 0; i < K; i++) {
        scanf("%d", &x);
        if (x == 0) {
            sum -= stk[--top];
        } else {
            stk[top++] = x;
            sum += x;
        }
    }
    printf("%lld\n", sum);
    return 0;
}