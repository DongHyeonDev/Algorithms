/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1806                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1806                           #+#        #+#      #+#    */
/*   Solved: 2026/02/13 15:52:33 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N, S;
    int arr[100000];
    
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    int left = 0;
    int right = 0;
    int sum = 0;
    int min_length = N + 1;
    
    while (true) {
        if (sum >= S) {
            // 조건 만족: 길이 갱신하고 left 증가
            min_length = min(min_length, right - left);
            sum -= arr[left];
            left++;
        } else if (right == N) {
            // 더 이상 확장 불가
            break;
        } else {
            // 합이 부족: right 증가
            sum += arr[right];
            right++;
        }
    }
    
    if (min_length == N + 1) {
        cout << "0\n";
    } else {
        cout << min_length << "\n";
    }
    
    return 0;
}