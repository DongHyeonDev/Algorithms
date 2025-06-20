/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 3003                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/3003                           #+#        #+#      #+#    */
/*   Solved: 2025/06/20 22:59:16 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

int main() {
    int king, queen, rook, bishop, knight, pawn;
    std::cin >> king >> queen >> rook >> bishop >> knight >> pawn;

    std::cout << 1 - king << ' '
              << 1 - queen << ' '
              << 2 - rook << ' '
              << 2 - bishop << ' '
              << 2 - knight << ' '
              << 8 - pawn << '\n';

    return 0;
}