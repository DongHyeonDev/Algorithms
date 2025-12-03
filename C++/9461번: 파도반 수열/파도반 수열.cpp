/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9461                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9461                           #+#        #+#      #+#    */
/*   Solved: 2025/12/03 13:24:26 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>

using namespace std;

vector<long long> P(101);

void precompute() {
    // 초기값
    P[1] = 1;
    P[2] = 1;
    P[3] = 1;

    // 동적 프로그래밍
    for (int i = 4; i <= 100; i++) {
        P[i] = P[i-2] + P[i-3];
    }
}

int main() {
    int T, N;

    // 미리 계산
    precompute();

    cin >> T;

    while (T--) {
        cin >> N;
        cout << P[N] << "\n";
    }

    return 0;
}