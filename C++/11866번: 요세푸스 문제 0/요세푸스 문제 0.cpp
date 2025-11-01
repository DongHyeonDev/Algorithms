/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11866                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11866                          #+#        #+#      #+#    */
/*   Solved: 2025/11/01 13:44:21 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <deque>

int main() {
    int N, K; 
    if (!(std::cin >> N >> K)) return 0;

    std::deque<int> dq;
    for (int i = 1; i <= N; i++) dq.push_back(i);

    std::cout << "<";
    for (int i = 0; i < N; i++) {
        for (int t = 0; t < K - 1; t++) {
            dq.push_back(dq.front());
            dq.pop_front();
        }
        int x = dq.front();
        dq.pop_front();

        if (i == N - 1) std::cout << x << ">";
        else std::cout << x << ", ";
    }
    return 0;
}