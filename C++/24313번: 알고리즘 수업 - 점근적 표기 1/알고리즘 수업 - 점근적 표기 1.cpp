/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 24313                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/24313                          #+#        #+#      #+#    */
/*   Solved: 2025/09/20 09:20:28 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

int main() {
    long long a1, a0, c, n0;
    if (!(std::cin >> a1 >> a0)) return 0;
    if (!(std::cin >> c)) return 0;
    if (!(std::cin >> n0)) return 0;

    int ok = 0;
    if (a1 > c) {
        ok = 0;
    } else if (a1 == c) {
        ok = (a0 <= 0);
    } else {
        ok = (a1 * n0 + a0 <= c * n0);
    }

    std::cout << (ok ? 1 : 0) << '\n';
    return 0;
}