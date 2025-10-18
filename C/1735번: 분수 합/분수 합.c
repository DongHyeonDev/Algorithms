/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1735                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1735                           #+#        #+#      #+#    */
/*   Solved: 2025/10/18 13:29:31 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int gcd(int x, int y) {
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

int main() {
    int a1, b1, a2, b2;
    if (scanf("%d %d %d %d", &a1, &b1, &a2, &b2) != 4) return 0;

    int numerator = a1 * b2 + a2 * b1;
    int denominator = b1 * b2;

    int divisor = gcd(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;

    printf("%d %d\n", numerator, denominator);
    return 0;
}