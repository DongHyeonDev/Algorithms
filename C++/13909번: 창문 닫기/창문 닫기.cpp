/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 13909                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/13909                          #+#        #+#      #+#    */
/*   Solved: 2025/10/24 13:34:47 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <cmath>

int main() {
    long long N;
    if (!(std::cin >> N)) return 0;

    long long ans = static_cast<long long>(floor(sqrt((long double)N)));
    std::cout << ans << '\n';
    return 0;
}