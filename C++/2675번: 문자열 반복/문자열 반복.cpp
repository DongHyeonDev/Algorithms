/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2675                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2675                           #+#        #+#      #+#    */
/*   Solved: 2025/05/29 14:36:09 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <string>

int main() {
    int T;
    std::cin >> T;

    while (T--) {
        int R;
        std::string S;
        std::cin >> R >> S;

        for (char ch : S) {
            for (int i = 0; i < R; ++i) {
                std::cout << ch;
            }
        }
        std::cout << '\n';
    }
    return 0;
}