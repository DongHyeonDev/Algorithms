/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2447                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2447                           #+#        #+#      #+#    */
/*   Solved: 2025/11/20 11:58:03 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

char grid[2187][2187];

void draw(int x, int y, int n) {
    if (n == 3) {
        grid[x][y] = '*';
        grid[x][y + 1] = '*';
        grid[x][y + 2] = '*';

        grid[x + 1][y] = '*';
        grid[x + 1][y + 1] = ' ';
        grid[x + 1][y + 2] = '*';

        grid[x + 2][y] = '*';
        grid[x + 2][y + 1] = '*';
        grid[x + 2][y + 2] = '*';
        return;
    }

    int third = n / 3;

    draw(x, y, third);
    draw(x, y + third, third);
    draw(x, y + 2 * third, third);

    draw(x + third, y, third);
    draw(x + third, y + 2 * third, third);

    draw(x + 2 * third, y, third);
    draw(x + 2 * third, y + third, third);
    draw(x + 2 * third, y + 2 * third, third);
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grid[i][j] = ' ';
        }
    }

    draw(0, 0, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}