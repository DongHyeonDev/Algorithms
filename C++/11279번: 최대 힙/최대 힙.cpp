/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11279                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11279                          #+#        #+#      #+#    */
/*   Solved: 2026/01/10 04:09:26 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <queue>

using namespace std;

int main() {
    int N;
    cin >> N;

    // 최대 힙 (기본이 최대 힙)
    priority_queue<int> max_heap;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        if (x > 0) {
            // x를 힙에 삽입
            max_heap.push(x);
        } else {
            // 최댓값 출력 및 제거
            if (max_heap.empty()) {
                cout << "0\n";
            } else {
                cout << max_heap.top() << "\n";
                max_heap.pop();
            }
        }
    }

    return 0;
}