/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1654                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1654                           #+#        #+#      #+#    */
/*   Solved: 2026/01/05 19:19:16 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int K, N;
vector<long long> cables;

// 길이 length로 잘랐을 때 만들 수 있는 랜선 개수
long long count_cables(long long length) {
    long long count = 0;
    for (int i = 0; i < K; i++) {
        count += cables[i] / length;
    }
    return count;
}

int main() {
    cin >> K >> N;

    cables.resize(K);
    long long max_length = 0;

    for (int i = 0; i < K; i++) {
        cin >> cables[i];
        max_length = max(max_length, cables[i]);
    }

    // 이분 탐색
    long long left = 1;
    long long right = max_length;
    long long result = 0;

    while (left <= right) {
        long long mid = (left + right) / 2;
        long long count = count_cables(mid);

        if (count >= N) {
            // N개 이상 만들 수 있으면 길이를 늘려봄
            result = mid;
            left = mid + 1;
        } else {
            // N개 미만이면 길이를 줄임
            right = mid - 1;
        }
    }

    cout << result << "\n";

    return 0;
}