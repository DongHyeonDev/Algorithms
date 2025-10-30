/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 18258                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/18258                          #+#        #+#      #+#    */
/*   Solved: 2025/10/30 14:41:35 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <deque>
#include <string>

int main() {
    int N; 
    if(!(std::cin >> N)) return 0;

    std::deque<int> dq;
    std::string cmd;
    while (N--) {
        std::cin >> cmd;
        if (cmd[0] == 'p' && cmd[1] == 'u') {
            int x; std::cin >> x;
            dq.push_back(x);
        } else if (cmd[0] == 'p') {
            if (dq.empty()) std::cout << -1 << '\n';
            else { std::cout << dq.front() << '\n'; dq.pop_front(); }
        } else if (cmd[0] == 's') {
            std::cout << (int)dq.size() << '\n';
        } else if (cmd[0] == 'e') {
            std::cout << (dq.empty() ? 1 : 0) << '\n';
        } else if (cmd[0] == 'f') {
            if (dq.empty()) std::cout << -1 << '\n';
            else std::cout << dq.front() << '\n';
        } else {
            if (dq.empty()) std::cout << -1 << '\n';
            else std::cout << dq.back() << '\n';
        }
    }
    return 0;
}