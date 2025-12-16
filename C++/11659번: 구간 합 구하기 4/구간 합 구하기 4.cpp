/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11659                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11659                          #+#        #+#      #+#    */
/*   Solved: 2025/12/16 15:18:51 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> arr(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    // 누적 합 계산
    // prefix[i] = arr[1] + arr[2] + ... + arr[i]
    vector<int> prefix(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        prefix[i] = prefix[i-1] + arr[i];
    }

    // 쿼리 처리
    for (int q = 0; q < M; q++) {
        int i, j;
        cin >> i >> j;

        // 구간 [i, j]의 합 = prefix[j] - prefix[i-1]
        int sum = prefix[j] - prefix[i-1];
        cout << sum << "\n";
    }

    return 0;
}