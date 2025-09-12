/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 5073                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/5073                           #+#        #+#      #+#    */
/*   Solved: 2025/09/12 10:29:43 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

int main() {
    while (true) {
        int a, b, c;
        if (!(std::cin >> a >> b >> c)) return 0;
        if (a == 0 && b == 0 && c == 0) break;

        std::array<int,3> s{a,b,c};
        std::sort(s.begin(), s.end());
        a = s[0]; b = s[1]; c = s[2];

        if (c >= a + b) {
            std::cout << "Invalid\n";
            continue;
        }

        if (a == b && b == c) {
            std::cout << "Equilateral\n";
        } else if (a == b || b == c || a == c) {
            std::cout << "Isosceles\n";
        } else {
            std::cout << "Scalene\n";
        }
    }
    return 0;
}