/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1436                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1436                           #+#        #+#      #+#    */
/*   Solved: 2025/09/25 16:58:26 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdbool.h>

static bool has666(int x) {
    int run = 0;
    while (x > 0) {
        if (x % 10 == 6) {
            if (++run >= 3) return true;
        } else {
            run = 0;
        }
        x /= 10;
    }
    return false;
}

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;

    int count = 0;
    int num = 666;
    while (1) {
        if (has666(num)) {
            if (++count == N) {
                printf("%d\n", num);
                break;
            }
        }
        ++num;
    }
    return 0;
}