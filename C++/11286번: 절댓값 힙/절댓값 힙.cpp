/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11286                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11286                          #+#        #+#      #+#    */
/*   Solved: 2026/01/12 12:37:12 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

// 커스텀 비교 함수
struct Compare {
    bool operator()(int a, int b) {
        // 절댓값이 다르면 절댓값이 작은 것 우선
        if (abs(a) != abs(b)) {
            return abs(a) > abs(b);
        }
        // 절댓값이 같으면 실제 값이 작은 것 우선
        return a > b;
    }
};

int main() {
    int N;
    cin >> N;

    priority_queue<int, vector<int>, Compare> pq;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;

        if (x != 0) {
            pq.push(x);
        } else {
            if (pq.empty()) {
                cout << "0\n";
            } else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
    }

    return 0;
}