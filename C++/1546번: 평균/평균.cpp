/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1546                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1546                           #+#        #+#      #+#    */
/*   Solved: 2025/05/15 23:14:08 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <iomanip>

int main() {
    int N;
    std::cin >> N;

    double scores[1000];
    for (int i = 0; i < N; i++) {
        std::cin >> scores[i];
    }

    // 최대값 M 찾기
    double M = scores[0];
    for (int i = 1; i < N; i++) {
        if (scores[i] > M) {
            M = scores[i];
        }
    }

    // 정규화된 점수 합산
    double sum = 0.0;
    for (int i = 0; i < N; i++) {
        sum += (scores[i] / M) * 100.0;
    }

    // 평균 계산 및 출력
    double average = sum / N;
    std::cout << std::fixed << std::setprecision(6) << average << "\n";

    return 0;
}