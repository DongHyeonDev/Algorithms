/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1193                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1193                           #+#        #+#      #+#    */
/*   Solved: 2025/07/31 22:40:38 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

int main() {
    int N;
    std::cin >> N;

    int layer = 1;
    int count = 1;

    if (N == 1) {
        std::cout << "1/1\n";
        return 0;
    }

    while (N > count) {
        layer++;
        count += layer;
    }

    int numerator = layer - (count - N);
    int denominator = 1 + (count - N);

    if (layer % 2 == 0) {
        std::swap(numerator, denominator);
    }

    std::cout << denominator << "/" << numerator << "\n";
    return 0;
}