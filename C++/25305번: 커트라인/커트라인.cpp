/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 25305                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/25305                          #+#        #+#      #+#    */
/*   Solved: 2025/09/29 15:47:29 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

int main() {
    int n, k;
    std::vector<int> arr;
    std::cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        int tmp;
        std::cin >> tmp;
        arr.push_back(tmp);
    }
    
    std::sort(arr.begin(), arr.end(), std::greater<>());
    std::cout << arr[k - 1] << '\n';

    return 0;
}