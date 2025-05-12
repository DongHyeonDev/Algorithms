/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10811                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10811                          #+#        #+#      #+#    */
/*   Solved: 2025/05/12 23:10:33 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <algorithm>

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

        // 양 끝에서부터 가운데로 스왑
        for (int l = i, r = j; l < r; l++, r--) {
            std::swap(basket[l], basket[r]);
        }
    }

    for (int i = 1; i <= N; i++) {
        std::cout << basket[i] << " ";
    }
    std::cout << "\n";
    return 0;
}
