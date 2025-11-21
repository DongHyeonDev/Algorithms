/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11729                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11729                          #+#        #+#      #+#    */
/*   Solved: 2025/11/21 14:19:11 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void hanoi(int n, int from, int to, int aux) {
    if (n == 1) {
        printf("%d %d\n", from, to);
        return;
    }

    hanoi(n - 1, from, aux, to);

    printf("%d %d\n", from, to);

    hanoi(n - 1, aux, to, from);
}

int main() {
    int n;
    scanf("%d", &n);

    long long total_moves = (1LL << n) - 1;
    printf("%lld\n", total_moves);

    hanoi(n, 1, 3, 2);

    return 0;
}