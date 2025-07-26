/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2720                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2720                           #+#        #+#      #+#    */
/*   Solved: 2025/07/26 20:52:23 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int C;
        scanf("%d", &C);

        int quarters = C / 25;
        C %= 25;

        int dimes = C / 10;
        C %= 10;

        int nickels = C / 5;
        C %= 5;

        int pennies = C;

        printf("%d %d %d %d\n", quarters, dimes, nickels, pennies);
    }

    return 0;
}