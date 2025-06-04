/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1152                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1152                           #+#        #+#      #+#    */
/*   Solved: 2025/06/04 20:35:25 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <string>

int main() {
    std::string str;
    getline(std::cin, str);  // 공백 포함 전체 입력

    int count = 0;
    bool inWord = false;

    for (char c : str) {
        if (c != ' ' && !inWord) {
            count++;        // 단어의 시작
            inWord = true;
        } else if (c == ' ') {
            inWord = false; // 단어의 끝
        }
    }

    std::cout << count << "\n";
    return 0;
}