/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1764                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1764                           #+#        #+#      #+#    */
/*   Solved: 2025/10/13 07:36:05 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    int N, M;
    if (!(std::cin >> N >> M)) return 0;

    std::unordered_set<std::string> unheard;
    unheard.reserve(N * 2);
    for (int i = 0; i < N; ++i) {
        std::string name; std::cin >> name;
        unheard.insert(name);
    }

    std::vector<std::string> ans;
    ans.reserve(std::min(N, M));
    for (int i = 0; i < M; ++i) {
        std::string name; std::cin >> name;
        if (unheard.find(name) != unheard.end()) {
            ans.push_back(name);
        }
    }

    std::sort(ans.begin(), ans.end());
    std::cout << ans.size() << '\n';
    for (auto& s : ans) std::cout << s << '\n';
    return 0;
}