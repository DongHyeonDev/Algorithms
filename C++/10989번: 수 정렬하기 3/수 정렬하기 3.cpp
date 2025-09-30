/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10989                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10989                          #+#        #+#      #+#    */
/*   Solved: 2025/09/30 16:53:12 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

int main() {
    int n;
    std::vector<int> arr;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        int tmp;
        std::cin >> tmp;
        arr.push_back(tmp);
    }

    std::sort(arr.begin(), arr.end());
    for (const auto& num : arr) {
        std::cout << num << '\n';
    }

    return 0;
}