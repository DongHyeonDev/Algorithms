/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2565                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2565                           #+#        #+#      #+#    */
/*   Solved: 2025/12/13 03:48:06 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Wire {
    int a;
    int b;
};

bool compare(const Wire& w1, const Wire& w2) {
    return w1.a < w2.a;
}

int main() {
    int N;
    cin >> N;

    vector<Wire> wires(N);
    for (int i = 0; i < N; i++) {
        cin >> wires[i].a >> wires[i].b;
    }

    // A 위치 기준으로 정렬
    sort(wires.begin(), wires.end(), compare);

    // B 위치에서 LIS 찾기
    vector<int> dp(N, 1);
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (wires[j].b < wires[i].b) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // LIS의 최대 길이 찾기
    int lis_length = *max_element(dp.begin(), dp.end());

    // 제거해야 할 전깃줄의 개수
    int result = N - lis_length;

    cout << result << "\n";

    return 0;
}