/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 17103                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/17103                          #+#        #+#      #+#    */
/*   Solved: 2025/10/23 08:53:33 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>

int main() {
    const int MAXN = 1000000;
    std::vector<char> composite(MAXN + 1, 0);

    composite[0] = composite[1] = 1;
    for (int p = 2; p * p <= MAXN; ++p) {
        if (!composite[p]) {
            for (int q = p * p; q <= MAXN; q += p) composite[q] = 1;
        }
    }

    int T; 
    if (!(std::cin >> T)) return 0;

    while (T--) {
        int N; 
        std::cin >> N;

        int cnt = 0;
        for (int p = 2; p <= N / 2; ++p) {
            if (!composite[p] && !composite[N - p]) ++cnt;
        }
        std::cout << cnt << '\n';
    }
    return 0;
}