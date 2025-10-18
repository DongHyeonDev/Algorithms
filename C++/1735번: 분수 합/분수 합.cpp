/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1735                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1735                           #+#        #+#      #+#    */
/*   Solved: 2025/10/18 13:29:37 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <algorithm>

int gcd(int x, int y) {
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

int main() {
    int a1, b1, a2, b2;
    if (!(std::cin >> a1 >> b1 >> a2 >> b2)) return 0;

    int numerator = a1 * b2 + a2 * b1;
    int denominator = b1 * b2;

    int g = gcd(numerator, denominator);
    numerator /= g;
    denominator /= g;

    std::cout << numerator << ' ' << denominator << '\n';
    return 0;
}