/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11651                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11651                          #+#        #+#      #+#    */
/*   Solved: 2025/10/04 12:16:55 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i].first >> arr[i].second;
    }

    std::sort(arr.begin(), arr.end(), [](const auto& a, const auto& b) {
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return a.second < b.second;
    });

    for (const auto& point : arr) {
        std::cout << point.first << ' ' << point.second << '\n';
    }

    return 0;
}