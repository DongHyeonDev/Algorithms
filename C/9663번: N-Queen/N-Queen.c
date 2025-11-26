/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9663                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9663                           #+#        #+#      #+#    */
/*   Solved: 2025/11/26 11:54:23 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int N;
int count = 0;
int cols[15];

int is_safe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (cols[i] == col) {
            return 0;
        }

        if (abs(cols[i] - col) == abs(i - row)) {
            return 0;
        }
    }

    return 1;
}

void backtrack(int row) {
    if (row == N) {
        count++;
        return;
    }

    for (int col = 0; col < N; col++) {
        if (is_safe(row, col)) {
            cols[row] = col;

            backtrack(row + 1);
        }
    }
}

int main() {
    scanf("%d", &N);

    backtrack(0);

    printf("%d\n", count);

    return 0;
}