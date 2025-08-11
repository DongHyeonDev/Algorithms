/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9506                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9506                           #+#        #+#      #+#    */
/*   Solved: 2025/08/11 16:57:00 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

int main() {
    int n;
    while (std::cin >> n && n != -1) {
        int sum = 0;
        for (int i = 1; i <= n / 2; ++i) {
            if (n % i == 0) {
                sum += i;
            }
        }
        if (sum == n) {
            std::cout << n << " = ";
            for (int i = 1; i <= n / 2; ++i) {
                if (n % i == 0) {
                    std::cout << i;
                    if (i != n / 2) {
                        std::cout << " + ";
                    }
                }
            }
            std::cout << std::endl;
        } else {
            std::cout << n << " is NOT perfect." << std::endl;
        }
    }
    return 0;
}