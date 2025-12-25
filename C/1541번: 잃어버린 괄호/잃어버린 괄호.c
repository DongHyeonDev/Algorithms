/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1541                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1541                           #+#        #+#      #+#    */
/*   Solved: 2025/12/25 17:17:10 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char expression[51];
    scanf("%s", expression);

    int len = strlen(expression);
    int result = 0;
    int current_num = 0;
    int is_minus = 0;  // 첫 번째 - 이후인지 여부

    for (int i = 0; i <= len; i++) {
        if (expression[i] >= '0' && expression[i] <= '9') {
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
            if (expression[i] == '-') {
                is_minus = 1;
            }
        }
    }

    printf("%d\n", result);

    return 0;
}