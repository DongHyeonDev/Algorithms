/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10813                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10813                          #+#        #+#      #+#    */
/*   Solved: 2025/05/09 21:57:37 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

int main() {
    int N, M;
    std::cin >> N >> M;

    int basket[101];
    for (int i = 1; i <= N; i++) {
        basket[i] = i;
    }

    for (int cmd = 0; cmd < M; cmd++) {
        int i, j;
        std::cin >> i >> j;
        int tmp = basket[i];
        basket[i] = basket[j];
        basket[j] = tmp;
    }

    for (int i = 1; i <= N; i++) {
        std::cout << basket[i] << " ";
    }
    std::cout << "\n";
    return 0;
}
