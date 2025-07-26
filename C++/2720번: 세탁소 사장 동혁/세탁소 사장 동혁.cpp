/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2720                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2720                           #+#        #+#      #+#    */
/*   Solved: 2025/07/26 20:52:30 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

int main() {
    int T;
    std::cin >> T;

    while (T--) {
        int C;
        std::cin >> C;

        int quarters = C / 25;
        C %= 25;

        int dimes = C / 10;
        C %= 10;

        int nickels = C / 5;
        C %= 5;

        int pennies = C;

        std::cout << quarters << ' '
             << dimes    << ' '
             << nickels  << ' '
             << pennies  << '\n';
    }

    return 0;
}