/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10816                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10816                          #+#        #+#      #+#    */
/*   Solved: 2025/10/12 12:43:54 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <unordered_map>

int main() {
    int n; 
    if (!(std::cin >> n)) return 0;

    std::unordered_map<int, int> freq;
    freq.reserve(n * 2);
    for (int i = 0; i < n; ++i) {
        int x; std::cin >> x;
        ++freq[x];
    }

    int m;
    std::cin >> m;
    for (int i = 0; i < m; ++i) {
        int q;
        std::cin >> q;
        auto it = freq.find(q);
        int cnt = (it == freq.end() ? 0 : it->second);
        std::cout << cnt << (i + 1 == m ? '\n' : ' ');
    }
    return 0;
}