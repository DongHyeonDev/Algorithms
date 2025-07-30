/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2292                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2292                           #+#        #+#      #+#    */
/*   Solved: 2025/07/30 16:40:41 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int layer = 1;
    int count = 6;

    if (N == 1) {
        printf("1\n");
        return 0;
    }

    while (N > 1) {
        N -= count;
        count += 6;
        layer++;
    }

    printf("%d\n", layer);
    return 0;
}