/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 7785                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/7785                           #+#        #+#      #+#    */
/*   Solved: 2025/10/10 11:39:09 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    int n; 
    if (!(std::cin >> n)) return 0;

    std::unordered_set<std::string> in;
    in.reserve(n * 2);

    for (int i = 0; i < n; ++i) {
        std::string name, op;
        std::cin >> name >> op;
        if (op[0] == 'e') in.insert(name);
        else in.erase(name);
    }

    std::vector<std::string> ans(in.begin(), in.end());
    std::sort(ans.begin(), ans.end(), std::greater<std::string>());

    for (auto& s : ans) std::cout << s << '\n';
    return 0;
}