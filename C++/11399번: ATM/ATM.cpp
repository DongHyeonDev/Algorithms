/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11399                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11399                          #+#        #+#      #+#    */
/*   Solved: 2025/12/24 19:28:13 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> time(N);
    for (int i = 0; i < N; i++) {
        cin >> time[i];
    }

    // 오름차순 정렬
    sort(time.begin(), time.end());

    int total = 0;
    int cumulative = 0;

    for (int i = 0; i < N; i++) {
        cumulative += time[i];  // 누적 시간
        total += cumulative;     // 각 사람의 대기+처리 시간 합산
    }

    cout << total << "\n";

    return 0;
}