/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2581                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2581                           #+#        #+#      #+#    */
/*   Solved: 2025/08/27 22:35:30 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

int main() {
    int m, n;
    std::cin >> m >> n;

    int sum = 0;
    int min_prime = -1;

    for (int num = m; num <= n; ++num) {
        if (num < 2) continue;
        bool is_prime = true;
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) {
            sum += num;
            if (min_prime == -1) {
                min_prime = num;
            }
        }
    }

    if (sum == 0) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << sum << std::endl;
        std::cout << min_prime << std::endl;
    }

    return 0;
}