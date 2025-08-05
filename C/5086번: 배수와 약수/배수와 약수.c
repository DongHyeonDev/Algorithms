/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 5086                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/5086                           #+#        #+#      #+#    */
/*   Solved: 2025/08/05 18:07:32 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int main() {
    int a, b;

    while (1) {
        scanf("%d %d", &a, &b);
        if (a == 0 && b == 0) break;

        if (b % a == 0) {
            printf("factor\n");
        } else if (a % b == 0) {
            printf("multiple\n");
        } else {
            printf("neither\n");
        }
    }

    return 0;
}