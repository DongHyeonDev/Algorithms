/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 24313                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/24313                          #+#        #+#      #+#    */
/*   Solved: 2025/09/20 09:20:35 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int main() {
    long long a1, a0, c, n0;
    if (scanf("%lld %lld", &a1, &a0) != 2) return 0;
    if (scanf("%lld", &c) != 1) return 0;
    if (scanf("%lld", &n0) != 1) return 0;

    int ok = 0;
    if (a1 > c) {
        ok = 0;
    } else if (a1 == c) {
        ok = (a0 <= 0);
    } else {
        ok = (a1 * n0 + a0 <= c * n0);
    }

    printf("%d\n", ok ? 1 : 0);
    return 0;
}