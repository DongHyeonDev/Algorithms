/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 5622                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/5622                           #+#        #+#      #+#    */
/*   Solved: 2025/06/06 22:48:59 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <string>

int main() {
    std::string str;
    std::cin >> str;

    int total_time = 0;
    for (char c : str) {
        if (c >= 'A' && c <= 'C') {
            total_time += 3;
        } else if (c >= 'D' && c <= 'F') {
            total_time += 4;
        } else if (c >= 'G' && c <= 'I') {
            total_time += 5;
        } else if (c >= 'J' && c <= 'L') {
            total_time += 6;
        } else if (c >= 'M' && c <= 'O') {
            total_time += 7;
        } else if (c >= 'P' && c <= 'S') {
            total_time += 8;
        } else if (c >= 'T' && c <= 'V') {
            total_time += 9;
        } else if (c >= 'W' && c <= 'Z') {
            total_time += 10;
        }
    }

    std::cout << total_time << "\n";
    return 0;
}