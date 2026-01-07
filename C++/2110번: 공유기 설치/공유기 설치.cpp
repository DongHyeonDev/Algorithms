/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2110                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2110                           #+#        #+#      #+#    */
/*   Solved: 2026/01/07 20:52:19 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;
vector<int> houses;

// 최소 거리 distance로 공유기를 몇 개 설치할 수 있는지
int count_routers(int distance) {
    int count = 1;  // 첫 번째 집에 무조건 설치
    int last_installed = houses[0];

    for (int i = 1; i < N; i++) {
        if (houses[i] - last_installed >= distance) {
            count++;
            last_installed = houses[i];
        }
    }

    return count;
}

int main() {
    cin >> N >> C;

    houses.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> houses[i];
    }

    // 정렬 (필수!)
    sort(houses.begin(), houses.end());

    // 이분 탐색
    int left = 1;
    int right = houses[N - 1] - houses[0];
    int result = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        int count = count_routers(mid);

        if (count >= C) {
            // C개 이상 설치 가능하면 거리를 늘려봄
            result = mid;
            left = mid + 1;
        } else {
            // C개 미만이면 거리를 줄임
            right = mid - 1;
        }
    }

    cout << result << "\n";

    return 0;
}