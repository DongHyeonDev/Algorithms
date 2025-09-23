/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 19532                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/19532                          #+#        #+#      #+#    */
/*   Solved: 2025/09/23 15:33:57 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int main() {
    long long a, b, c, d, e, f;
    if (scanf("%lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f) != 6) return 0;

    long long det  = a*e - b*d;
    long long detX = c*e - b*f;
    long long detY = a*f - c*d;

    long long x = detX / det;
    long long y = detY / det;

    printf("%lld %lld\n", x, y);
    return 0;
}