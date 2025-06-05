/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2908                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2908                           #+#        #+#      #+#    */
/*   Solved: 2025/06/05 21:31:43 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

// 세 자리 문자열을 뒤집어 정수로 반환하는 헬퍼 함수
int reverse_int(const char *s) {
    // 예: "734" → "437" → 437
    return (s[2] - '0') * 100 + (s[1] - '0') * 10 + (s[0] - '0');
}

int main() {
    char A[4], B[4];
    scanf("%3s %3s", A, B);

    int revA = reverse_int(A);
    int revB = reverse_int(B);

    // 두 값을 비교하여 큰 쪽을 출력
    printf("%d\n", (revA > revB) ? revA : revB);
    return 0;
}