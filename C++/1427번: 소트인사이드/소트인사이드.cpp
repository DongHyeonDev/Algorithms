/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1427                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1427                           #+#        #+#      #+#    */
/*   Solved: 2025/09/30 22:11:45 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::string n;
    std::cin >> n;

    std::vector<char> arr;

    for (const auto& num : n) {
        arr.push_back(num);
    }

    std::sort(arr.begin(), arr.end(), std::greater<>());
    for (const auto& num : arr) {
        std::cout << num;
    }

    return 0;
}