/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1316                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1316                           #+#        #+#      #+#    */
/*   Solved: 2025/07/03 12:17:29 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <string>

bool isGroupWord(const std::string& word) {
    bool seen[26] = { false };
    char prev = 0;
    for (char c : word) {
        if (c != prev) {
            if (seen[c - 'a']) return false;
            seen[c - 'a'] = true;
        }
        prev = c;
    }
    return true;
}

int main() {
    int N;
    std::cin >> N;

    int count = 0;
    for (int i = 0; i < N; i++) {
        std::string word;
        std::cin >> word;
        if (isGroupWord(word)) count++;
    }

    std::cout << count << "\n";
    return 0;
}