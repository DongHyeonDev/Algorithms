/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2231                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2231                           #+#        #+#      #+#    */
/*   Solved: 2025/09/22 15:14:40 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

int digit_sum(int x) {
    int s = 0;
    while (x > 0) { s += x % 10; x /= 10; }
    return s;
}

int main() {
    int N;
    if (!(std::cin >> N)) return 0;

    int answer = 0;
    for (int m = 1; m < N; ++m) {
        if (m + digit_sum(m) == N) {
            answer = m;
            break;
        }
    }
    std::cout << answer << '\n';
    return 0;
}