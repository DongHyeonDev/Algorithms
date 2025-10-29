/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 12789                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/12789                          #+#        #+#      #+#    */
/*   Solved: 2025/10/29 19:24:50 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <stack>
#include <vector>

int main() {
    int n; 
    if (!(std::cin >> n)) return 0;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];

    std::vector<int> stk; stk.reserve(n);
    int need = 1;

    for (int x : a) {
        while (!stk.empty() && stk.back() == need) { stk.pop_back(); ++need; }
        if (x == need) ++need;
        else stk.push_back(x);
    }
    while (!stk.empty() && stk.back() == need) { stk.pop_back(); ++need; }

    std::cout << (stk.empty() ? "Nice" : "Sad") << '\n';
    return 0;
}