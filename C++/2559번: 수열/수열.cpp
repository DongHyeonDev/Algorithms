/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2559                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2559                           #+#        #+#      #+#    */
/*   Solved: 2025/12/17 12:50:19 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> temp(N);
    for (int i = 0; i < N; i++) {
        cin >> temp[i];
    }

    // 처음 K개의 합
    int current_sum = 0;
    for (int i = 0; i < K; i++) {
        current_sum += temp[i];
    }

    int max_sum = current_sum;

    // 슬라이딩 윈도우
    for (int i = K; i < N; i++) {
        // 왼쪽 원소 제거, 오른쪽 원소 추가
        current_sum = current_sum - temp[i-K] + temp[i];
        max_sum = max(max_sum, current_sum);
    }

    cout << max_sum << "\n";

    return 0;
}