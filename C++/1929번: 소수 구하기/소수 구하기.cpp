/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1929                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1929                           #+#        #+#      #+#    */
/*   Solved: 2025/10/21 10:43:27 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

int main() {
    int M, N;
    if (!(std::cin >> M >> N)) return 0;

    std::vector<char> composite(N + 1, 0);
    composite[0] = 1;
    if (N >= 1) composite[1] = 1;

    for (int p = 2; p * p <= N; ++p) {
        if (!composite[p]) {
            for (int q = p * p; q <= N; q += p) {
                composite[q] = 1;
            }
        }
    }

    for (int x = M; x <= N; ++x) {
        if (!composite[x]) {
            std::cout << x << '\n';
        }
    }
    return 0;
}