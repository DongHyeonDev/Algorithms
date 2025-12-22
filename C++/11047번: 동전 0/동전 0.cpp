/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11047                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11047                          #+#        #+#      #+#    */
/*   Solved: 2025/12/22 14:00:29 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> coins(N);
    for (int i = 0; i < N; i++) {
        cin >> coins[i];
    }

    int count = 0;

    // 가장 큰 동전부터 사용
    for (int i = N - 1; i >= 0; i--) {
        if (K >= coins[i]) {
            count += K / coins[i];  // 현재 동전으로 만들 수 있는 개수
            K %= coins[i];           // 남은 금액
        }

        if (K == 0) break;  // 목표 금액 달성
    }

    cout << count << "\n";

    return 0;
}