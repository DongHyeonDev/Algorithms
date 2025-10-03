/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11650                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11650                          #+#        #+#      #+#    */
/*   Solved: 2025/10/01 00:15:11 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::vector<std::pair<int, int>> arr;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        int x, y;
        std::cin >> x >> y;
        arr.emplace_back(x, y);
    }

    std::sort(arr.begin(), arr.end());
    for (const auto& p : arr) {
        std::cout << p.first << ' ' << p.second << '\n';
    }

    return 0;
}