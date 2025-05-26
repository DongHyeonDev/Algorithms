/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10809                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10809                          #+#        #+#      #+#    */
/*   Solved: 2025/05/26 15:04:54 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <string>

int main() {
    std::string S;
    std::cin >> S;

    int pos[26];  // 알파벳 위치 저장
    std::fill(pos, pos + 26, -1);  // -1로 초기화

    for (int i = 0; i < S.length(); ++i) {
        int idx = S[i] - 'a';
        if (pos[idx] == -1) {
            pos[idx] = i;  // 처음 등장한 위치만 저장
        }
    }

    for (int i = 0; i < 26; ++i) {
        std::cout << pos[i] << " ";
    }
    std::cout << '\n';
    return 0;
}