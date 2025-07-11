/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2738                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2738                           #+#        #+#      #+#    */
/*   Solved: 2025/07/11 21:43:08 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>

int main() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> A(N, std::vector<int>(M));
    std::vector<std::vector<int>> B(N, std::vector<int>(M));

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            std::cin >> A[i][j];

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            std::cin >> B[i][j];

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cout << A[i][j] + B[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}