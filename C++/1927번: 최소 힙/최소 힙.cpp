/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1927                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1927                           #+#        #+#      #+#    */
/*   Solved: 2026/01/11 19:01:11 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <queue>

using namespace std;

int main() {
    int N;
    cin >> N;

    // 최소 힙
    priority_queue<int, vector<int>, greater<int>> min_heap;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        if (x > 0) {
            // x를 힙에 삽입
            min_heap.push(x);
        } else {
            // 최솟값 출력 및 제거
            if (min_heap.empty()) {
                cout << "0\n";
            } else {
                cout << min_heap.top() << "\n";
                min_heap.pop();
            }
        }
    }

    return 0;
}