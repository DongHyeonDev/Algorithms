/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 12015                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/12015                          #+#        #+#      #+#    */
/*   Solved: 2026/01/09 19:23:26 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    vector<int> lis;

    for (int i = 0; i < N; i++) {
        // arr[i] 이상인 첫 번째 위치 찾기
        auto pos = lower_bound(lis.begin(), lis.end(), arr[i]);
        
        if (pos == lis.end()) {
            // 가장 큰 값이면 추가
            lis.push_back(arr[i]);
        } else {
            // 적절한 위치에 교체
            *pos = arr[i];
        }
    }

    cout << lis.size() << "\n";

    return 0;
}