/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2346                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2346                           #+#        #+#      #+#    */
/*   Solved: 2025/11/03 14:12:48 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <deque>

struct Node {
    int idx, mv;
};

int main() {
    int N; 
    if (!(std::cin >> N)) return 0;

    std::deque<Node> dq;
    dq.resize(0);
    for (int i = 1; i <= N; ++i) {
        int v;
        std::cin >> v;
        dq.push_back({i, v});
    }

    Node cur = dq.front();
    dq.pop_front();
    std::cout << cur.idx;
    int k = cur.mv;

    while (!dq.empty()) {
        if (k > 0) {
            for (int r = 0; r < k - 1; ++r) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
            cur = dq.front();
            dq.pop_front();
        } else {
            for (int r = 0; r < -k; ++r) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
            cur = dq.front();
            dq.pop_front();
        }
        std::cout << ' ' << cur.idx;
        k = cur.mv;
    }
    std::cout << '\n';
    return 0;
}