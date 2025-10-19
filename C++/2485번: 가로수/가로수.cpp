/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2485                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2485                           #+#        #+#      #+#    */
/*   Solved: 2025/10/19 14:57:23 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>

int gcd(int a, int b) {
    while (b) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a >= 0 ? a : -a;
}

int main() {
    int N; 
    if (!(std::cin >> N)) return 0;

    std::vector<int> x(N);
    for (int i = 0; i < N; ++i) std::cin >> x[i];

    int g = 0;
    for (int i = 0; i < N - 1; ++i) {
        int d = x[i + 1] - x[i];
        g = (i == 0) ? d : gcd(g, d);
    }

    int add = 0;
    for (int i = 0; i < N - 1; ++i) {
        int d = x[i + 1] - x[i];
        add += d / g - 1;
    }

    std::cout << add << '\n';
    return 0;
}