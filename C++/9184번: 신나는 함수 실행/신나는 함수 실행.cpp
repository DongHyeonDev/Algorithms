/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9184                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9184                           #+#        #+#      #+#    */
/*   Solved: 2025/12/01 18:43:54 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <cstring>

using namespace std;

int dp[21][21][21];

int w(int a, int b, int c) {
    // 기저 조건 1: a, b, c 중 하나라도 0 이하
    if (a <= 0 || b <= 0 || c <= 0) {
        return 1;
    }
    
    // 기저 조건 2: a, b, c 중 하나라도 20 초과
    if (a > 20 || b > 20 || c > 20) {
        return w(20, 20, 20);
    }
    
    // 메모이제이션: 이미 계산된 값이 있으면 반환
    if (dp[a][b][c] != 0) {
        return dp[a][b][c];
    }
    
    // 재귀 계산
    if (a < b && b < c) {
        dp[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
    } else {
        dp[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
    }
    
    return dp[a][b][c];
}

int main() {
    int a, b, c;
    
    // dp 배열 초기화 (0으로)
    memset(dp, 0, sizeof(dp));
    
    while (true) {
        cin >> a >> b >> c;
        
        // 종료 조건
        if (a == -1 && b == -1 && c == -1) {
            break;
        }
        
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << "\n";
    }
    
    return 0;
}