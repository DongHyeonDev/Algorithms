/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1018                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1018                           #+#        #+#      #+#    */
/*   Solved: 2025/09/24 14:37:45 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int main() {
    int N, M;
    if (scanf("%d %d", &N, &M) != 2) return 0;

    char board[51][51];
    for (int i = 0; i < N; ++i) {
        scanf("%s", board[i]);
    }

    int answer = 64;
    for (int r = 0; r <= N - 8; ++r) {
        for (int c = 0; c <= M - 8; ++c) {
            int repaintW = 0;
            for (int i = 0; i < 8; ++i) {
                for (int j = 0; j < 8; ++j) {
                    char expected = ((i + j) % 2 == 0) ? 'W' : 'B';
                    if (board[r + i][c + j] != expected) ++repaintW;
                }
            }

            int repaint = repaintW < (64 - repaintW) ? repaintW : (64 - repaintW);
            if (repaint < answer) answer = repaint;
        }
    }

    printf("%d\n", answer);
    return 0;
}