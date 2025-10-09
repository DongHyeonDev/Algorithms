/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 14425                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/14425                          #+#        #+#      #+#    */
/*   Solved: 2025/10/09 10:57:37 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <unordered_set>
#include <string>

int main() {
    int N, M;
    if (!(std::cin >> N >> M)) return 0;

    std::unordered_set<std::string> S;
    S.reserve(N * 2);

    std::string s;
    for (int i = 0; i < N; ++i) {
        std::cin >> s;
        S.insert(s);
    }

    int ans = 0;
    for (int i = 0; i < M; ++i) {
        std::cin >> s;
        if (S.find(s) != S.end()) ++ans;
    }
    std::cout << ans << '\n';
    return 0;
}