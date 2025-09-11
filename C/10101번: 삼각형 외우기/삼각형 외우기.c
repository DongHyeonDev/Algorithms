/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10101                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10101                          #+#        #+#      #+#    */
/*   Solved: 2025/09/11 13:44:10 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int main() {
    int a, b, c;
    if (scanf("%d %d %d", &a, &b, &c) != 3) return 0;

    if (a + b + c != 180) {
        printf("Error\n");
    } else if (a == 60 && b == 60 && c == 60) {
        printf("Equilateral\n");
    } else if (a == b || b == c || a == c) {
        printf("Isosceles\n");
    } else {
        printf("Scalene\n");
    }
    return 0;
}