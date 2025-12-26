/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 13305                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/13305                          #+#        #+#      #+#    */
/*   Solved: 2025/12/26 09:52:36 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long> distance(N - 1);
    vector<long long> price(N);

    // 거리 입력
    for (int i = 0; i < N - 1; i++) {
        cin >> distance[i];
    }

    // 가격 입력
    for (int i = 0; i < N; i++) {
        cin >> price[i];
    }

    long long total_cost = 0;
    long long min_price = price[0];  // 현재까지 본 최소 가격

    // 마지막 도시 전까지만 주유
    for (int i = 0; i < N - 1; i++) {
        // 현재까지의 최소 가격으로 주유
        total_cost += min_price * distance[i];

        // 다음 도시 가격이 더 싸면 갱신
        if (price[i + 1] < min_price) {
            min_price = price[i + 1];
        }
    }

    cout << total_cost << "\n";

    return 0;
}