/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1157                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1157                           #+#        #+#      #+#    */
/*   Solved: 2025/06/28 19:41:28 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::string S;
    std::cin >> S;

    int freq[26] = {0};

    for (char c : S) {
        c = std::toupper(c);
        freq[c - 'A']++;
    }

    int count_max = 0;
    char result = '?';
    for (int i = 0; i < 26; i++) {
        if (freq[i] > count_max) {
            count_max = freq[i];
            result = 'A' + i;
        } else if (freq[i] == count_max) {
            result = '?';
        }
    }

    std::cout << result << "\n";
    return 0;
}