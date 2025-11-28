/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 14888                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/14888                          #+#        #+#      #+#    */
/*   Solved: 2025/11/28 18:12:19 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <limits.h>

int N;
int numbers[11];
int operators[4];  // +, -, *, /
int max_result = INT_MIN;
int min_result = INT_MAX;

// 백트래킹으로 모든 연산자 조합 시도
// idx: 현재까지 계산한 수의 인덱스 (다음 계산할 숫자는 numbers[idx])
// current: 현재까지의 계산 결과
void backtrack(int idx, int current) {
    // 기저 조건: 모든 수를 사용함
    if (idx == N) {
        if (current > max_result) {
            max_result = current;
        }
        if (current < min_result) {
            min_result = current;
        }
        return;
    }

    // 덧셈
    if (operators[0] > 0) {
        operators[0]--;
        backtrack(idx + 1, current + numbers[idx]);
        operators[0]++;
    }

    // 뺄셈
    if (operators[1] > 0) {
        operators[1]--;
        backtrack(idx + 1, current - numbers[idx]);
        operators[1]++;
    }

    // 곱셈
    if (operators[2] > 0) {
        operators[2]--;
        backtrack(idx + 1, current * numbers[idx]);
        operators[2]++;
    }

    // 나눗셈
    if (operators[3] > 0) {
        operators[3]--;
        // 음수 나눗셈 처리
        int result;
        if (current < 0) {
            result = -(-current / numbers[idx]);
        } else {
            result = current / numbers[idx];
        }
        backtrack(idx + 1, result);
        operators[3]++;
    }
}

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &numbers[i]);
    }

    for (int i = 0; i < 4; i++) {
        scanf("%d", &operators[i]);
    }

    // 첫 번째 수부터 시작
    backtrack(1, numbers[0]);

    printf("%d\n", max_result);
    printf("%d\n", min_result);

    return 0;
}