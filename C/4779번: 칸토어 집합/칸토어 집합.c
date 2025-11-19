/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 4779                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/4779                           #+#        #+#      #+#    */
/*   Solved: 2025/11/19 14:46:27 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
#include <math.h>

char line[14348908];

void cantor(int start, int length) {
    if (length == 1) {
        return;
    }

    int third = length / 3;

    for (int i = start + third; i < start + 2 * third; i++) {
        line[i] = ' ';
    }

    cantor(start, third);
    cantor(start + 2 * third, third);
}

int main() {
    int n;

    while (scanf("%d", &n) != EOF) {
        int length = (int)pow(3, n);

        for (int i = 0; i < length; i++) {
            line[i] = '-';
        }
        line[length] = '\0';

        cantor(0, length);

        printf("%s\n", line);
    }

    return 0;
}