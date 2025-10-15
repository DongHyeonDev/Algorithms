/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11478                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11478                          #+#        #+#      #+#    */
/*   Solved: 2025/10/15 12:42:26 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

int main() {
    std::string s;
    std::unordered_set<std::string> st;

    std::cin >> s;
    for (int i = 0; i < s.size(); i++) {
        for (int j = 1; i + j <= s.size(); j++) {
            st.insert(s.substr(i, j));
        }
    }
    std::cout << st.size();
    return 0;
}