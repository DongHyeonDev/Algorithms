/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 5073                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/5073                           #+#        #+#      #+#    */
/*   Solved: 2025/09/12 10:29:38 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int main() {
    while (1) {
        int a, b, c;
        if (scanf("%d %d %d", &a, &b, &c) != 3) return 0;
        if (a == 0 && b == 0 && c == 0) break;

        if (a > b) { int t = a; a = b; b = t; }
        if (b > c) { int t = b; b = c; c = t; }
        if (a > b) { int t = a; a = b; b = t; }

        if (c >= a + b) {
            printf("Invalid\n");
            continue;
        }

        if (a == b && b == c) {
            printf("Equilateral\n");
        } else if (a == b || b == c || a == c) {
            printf("Isosceles\n");
        } else {
            printf("Scalene\n");
        }
    }
    return 0;
}