/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 5086                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/5086                           #+#        #+#      #+#    */
/*   Solved: 2025/08/05 18:07:38 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

int main() {
    int a, b;

    while (true) {
        std::cin >> a >> b;
        if (a == 0 && b == 0) break;

        if (b % a == 0) {
            std::cout << "factor\n";
        } else if (a % b == 0) {
            std::cout << "multiple\n";
        } else {
            std::cout << "neither\n";
        }
    }
    
    return 0;
}