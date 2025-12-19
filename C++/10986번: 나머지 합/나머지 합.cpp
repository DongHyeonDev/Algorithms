/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 10986                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/10986                          #+#        #+#      #+#    */
/*   Solved: 2025/12/19 13:32:43 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    // 각 나머지의 개수를 세는 배열
    vector<long long> count(M, 0);

    // 누적 합의 나머지가 0인 경우를 위해 초기값 설정
    count[0] = 1;

    long long prefix_sum = 0;
    long long result = 0;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        prefix_sum += num;
        int remainder = ((prefix_sum % M) + M) % M;  // 음수 처리

        // 현재 나머지와 같은 나머지를 가진 이전 위치들과 쌍을 이룸
        result += count[remainder];

        // 현재 나머지 개수 증가
        count[remainder]++;
    }

    cout << result << "\n";

    return 0;
}