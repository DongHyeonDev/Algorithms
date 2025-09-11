/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10101                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10101                          #+#        #+#      #+#    */
/*   Solved: 2025/09/11 13:44:17 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

int main() {
    int a, b, c;
    if (!(std::cin >> a >> b >> c)) return 0;

    if (a + b + c != 180) {
        std::cout << "Error\n";
    } else if (a == 60 && b == 60 && c == 60) {
        std::cout << "Equilateral\n";
    } else if (a == b || b == c || a == c) {
        std::cout << "Isosceles\n";
    } else {
        std::cout << "Scalene\n";
    }
    return 0;
}