/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9063                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9063                           #+#        #+#      #+#    */
/*   Solved: 2025/09/10 12:27:50 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

int main() {
    int n; 
    if (!(std::cin >> n)) return 0;

    int x, y;
    std::cin >> x >> y;
    int minX = x;
    int maxX = x;
    int minY = y;
    int maxY = y;

    for (int i = 1; i < n; ++i) {
        std::cin >> x >> y;
        minX = std::min(minX, x);
        maxX = std::max(maxX, x);
        minY = std::min(minY, y);
        maxY = std::max(maxY, y);
    }

    long long width  = 1LL * (maxX - minX);
    long long height = 1LL * (maxY - minY);

    std::cout << (width * height) << '\n';
    return 0;
}