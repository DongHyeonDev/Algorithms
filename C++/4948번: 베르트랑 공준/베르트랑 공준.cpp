/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 4948                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/4948                           #+#        #+#      #+#    */
/*   Solved: 2025/10/22 11:46:24 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>

int main() {
    const int MAX = 246912;
    std::vector<char> comp(MAX + 1, 0);

    comp[0] = comp[1] = 1;
    for (int p = 2; p * p <= MAX; ++p) {
        if (!comp[p]) {
            for (int q = p * p; q <= MAX; q += p) comp[q] = 1;
        }
    }

    int n;
    while (std::cin >> n && n != 0) {
        int cnt = 0;
        for (int x = n + 1; x <= 2 * n; ++x)
            if (!comp[x]) ++cnt;
        std::cout << cnt << '\n';
    }
    return 0;
}