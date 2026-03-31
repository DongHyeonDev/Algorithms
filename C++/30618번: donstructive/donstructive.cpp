/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 30618                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/30618                          #+#        #+#      #+#    */
/*   Solved: 2026/03/31 16:25:48 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N; cin >> N;
    
    // 위치를 계수(기여도) 내림차순으로 정렬
    vector<int> positions(N);
    for (int i = 0; i < N; i++) positions[i] = i + 1;
    sort(positions.begin(), positions.end(), [&](int a, int b) {
        return (long long)a*(N-a+1) > (long long)b*(N-b+1);
    });
    
    vector<int> result(N + 1);
    for (int i = 0; i < N; i++) result[positions[i]] = N - i;
    
    for (int i = 1; i <= N; i++) {
        cout << result[i];
        if (i < N) cout << " ";
    }
    cout << "\n";
    return 0;
}