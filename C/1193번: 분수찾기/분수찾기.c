/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1193                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1193                           #+#        #+#      #+#    */
/*   Solved: 2025/07/31 22:40:31 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int layer = 1;
    int count = 1;

    if (N == 1) {
        printf("1/1\n");
        return 0;
    }

    while (N > count) {
        layer++;
        count += layer;
    }

    int numerator = layer - (count - N);
    int denominator = 1 + (count - N);

    if (layer % 2 == 0) {
        int temp = numerator;
        numerator = denominator;
        denominator = temp;
    }

    printf("%d/%d\n", denominator, numerator);
    return 0;
}