/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2480                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2480                           #+#        #+#      #+#    */
/*   Solved: 2025/04/04 23:13:34 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

int main() {
    int a, b, c;
    int prize = 0;
    std::cin >> a >> b >> c;

    if (a == b && b == c) {
        prize = 10000 + a * 1000;
    } else if (a == b || a == c) {
        prize = 1000 + a * 100;
    } else if (b == c) {
        prize = 1000 + b * 100;
    } else {
        int max = a;
        if (b > max) max = b;
        if (c > max) max = c;
        prize = max * 100;
    }

    std::cout << prize << std::endl;
    return 0;
}