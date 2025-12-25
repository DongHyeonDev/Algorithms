/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1541                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1541                           #+#        #+#      #+#    */
/*   Solved: 2025/12/25 17:17:17 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string expression;
    cin >> expression;

    int result = 0;
    int current_num = 0;
    bool is_minus = false;  // 첫 번째 - 이후인지 여부

    for (int i = 0; i <= expression.length(); i++) {
        if (i < expression.length() && expression[i] >= '0' && expression[i] <= '9') {
            // 숫자 파싱
            current_num = current_num * 10 + (expression[i] - '0');
        } else {
            // 연산자이거나 문자열 끝
            if (is_minus) {
                result -= current_num;  // - 이후는 모두 뺌
            } else {
                result += current_num;  // 처음은 더함
            }
            current_num = 0;

            // - 연산자를 만나면 이후 모든 수를 빼기
            if (i < expression.length() && expression[i] == '-') {
                is_minus = true;
            }
        }
    }

    cout << result << "\n";

    return 0;
}