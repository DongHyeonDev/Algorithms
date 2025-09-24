/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1018                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1018                           #+#        #+#      #+#    */
/*   Solved: 2025/09/24 14:37:53 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

int main() {
    int N, M;
    if (!(std::cin >> N >> M)) return 0;

    std::vector<std::string> board(N);
    for (int i = 0; i < N; ++i) std::cin >> board[i];

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
            int repaint = std::min(repaintW, 64 - repaintW);
            answer = std::min(answer, repaint);
        }
    }

    std::cout << answer << '\n';
    return 0;
}