/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2941                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2941                           #+#        #+#      #+#    */
/*   Solved: 2025/06/29 23:40:04 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::string str;
    std::cin >> str;

    std::vector<std::string> croatian = {
        "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="
    };

    int count = 0;
    for (size_t i = 0; i < str.length(); ) {
        if (str.substr(i, 3) == "dz=") {
            count++;
            i += 3;
        } else if (i + 1 < str.length()) {
            std::string two = str.substr(i, 2);
            if (std::find(croatian.begin(), croatian.end(), two) != croatian.end()) {
                count++;
                i += 2;
            } else {
                count++;
                i++;
            }
        } else {
            count++;
            i++;
        }
    }

    std::cout << count << "\n";
    return 0;
}