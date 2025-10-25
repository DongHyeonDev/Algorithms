/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 28278                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/28278                          #+#        #+#      #+#    */
/*   Solved: 2025/10/25 17:14:08 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

const int MAX = 1000000;
int s[MAX], top = 0;

int main() {
    int n, cmd, x;
    if (!(std::cin >> n)) return 0;
    
    while (n--) {
        std::cin >> cmd;
        if (cmd == 1) {
            std::cin >> x;
            s[top++] = x;
        } else if (cmd == 2) {
            if (top == 0) std::cout << -1 << '\n';
            else std::cout << s[--top] << '\n';
        } else if (cmd == 3) {
            std::cout << top << '\n';
        } else if (cmd == 4) {
            std::cout << (top == 0) << '\n';
        } else if (cmd == 5) {
            if (top == 0) std::cout << -1 << '\n';
            else std::cout << s[top - 1] << '\n';
        }
    }
    return 0;
}