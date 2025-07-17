/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10798                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10798                          #+#        #+#      #+#    */
/*   Solved: 2025/07/17 19:40:25 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <string>

int main() {
    std::string arr[5];
    for (int i = 0; i < 5; ++i) {
        std::getline(std::cin, arr[i]);
    }

    for (int j = 0; j < 15; ++j) {
        for (int i = 0; i < 5; ++i) {
            if (j < arr[i].size()) {
                std::cout << arr[i][j];
            }
        }
    }
    std::cout << "\n";
    return 0;
}