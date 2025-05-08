/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10810                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10810                          #+#        #+#      #+#    */
/*   Solved: 2025/05/08 23:02:16 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

int main() {
    int N, M;
    std::cin >> N >> M;

    int basket[100] = {0};

    for (int cmd = 0; cmd < M; ++cmd) {
        int i, j, k;
        std::cin >> i >> j >> k;
        for (int b = i; b <= j; ++b) {
            basket[b] = k;
        }
    }

    for (int b = 1; b <= N; ++b) {
        std::cout << basket[b] << " ";
    }
    std::cout << "\n";
    return 0;
}