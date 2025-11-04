/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 24511                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/24511                          #+#        #+#      #+#    */
/*   Solved: 2025/11/04 12:27:54 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <deque>
#include <vector>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<int> B(N);
    for (int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    std::deque<int> dq;
    for (int i = 0; i < N; i++) {
        if (A[i] == 0) {
            dq.push_back(B[i]);
        }
    }

    int M;
    std::cin >> M;

    for (int i = 0; i < M; i++) {
        int x;
        std::cin >> x;

        if (dq.empty()) {
            std::cout << x;
        } else {
            std::cout << dq.back();
            dq.pop_back();
            dq.push_front(x);
        }

        if (i < M - 1) std::cout << " ";
    }
    std::cout << "\n";

    return 0;
}