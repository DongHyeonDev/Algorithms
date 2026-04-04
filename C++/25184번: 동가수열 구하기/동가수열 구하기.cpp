/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 25184                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/25184                          #+#        #+#      #+#    */
/*   Solved: 2026/04/04 13:52:37 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
using namespace std;

int main() {
    int N; cin >> N;
    int half = N / 2;
    int lo = 1, hi = half + 1;
    bool first = true;
    
    // 큰 그룹과 작은 그룹 번갈아 출력
    while (hi <= N || lo <= half) {
        if (hi <= N) {
            if (!first) cout << " ";
            cout << hi++; first = false;
        }
        if (lo <= half) {
            if (!first) cout << " ";
            cout << lo++; first = false;
        }
    }
    cout << "\n";
    return 0;
}