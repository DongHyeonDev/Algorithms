/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2444                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2444                           #+#        #+#      #+#    */
/*   Solved: 2025/06/24 19:08:48 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

int main() {
    int N;
    std::cin >> N;

    for (int i = 1; i <= N; ++i) {
        int space = N - i;
        int star = 2 * i - 1;
        std::cout << std::string(space, ' ') << std::string(star, '*') << "\n";
    }

    for (int i = N - 1; i >= 1; --i) {
        int space = N - i;
        int star = 2 * i - 1;
        std::cout << std::string(space, ' ') << std::string(star, '*') << "\n";
    }

    return 0;
}