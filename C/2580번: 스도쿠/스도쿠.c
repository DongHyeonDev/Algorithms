/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2580                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2580                           #+#        #+#      #+#    */
/*   Solved: 2025/11/27 12:39:18 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int board[9][9];

// (row, col) 위치에 num을 놓을 수 있는지 확인
int is_valid(int row, int col, int num) {
    // 행 체크
    for (int i = 0; i < 9; i++) {
        if (board[row][i] == num) {
            return 0;
        }
    }

    // 열 체크
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == num) {
            return 0;
        }
    }

    // 3x3 박스 체크
    int box_row = (row / 3) * 3;
    int box_col = (col / 3) * 3;
    for (int i = box_row; i < box_row + 3; i++) {
        for (int j = box_col; j < box_col + 3; j++) {
            if (board[i][j] == num) {
                return 0;
            }
        }
    }

    return 1;
}

// 백트래킹으로 스도쿠 풀기
int solve() {
    // 빈 칸 찾기
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == 0) {
                // 1부터 9까지 시도
                for (int num = 1; num <= 9; num++) {
                    if (is_valid(row, col, num)) {
                        // num 배치
                        board[row][col] = num;

                        // 다음 빈 칸으로 진행
                        if (solve()) {
                            return 1;  // 성공
                        }

                        // 백트래킹
                        board[row][col] = 0;
                    }
                }

                // 1~9 모두 실패
                return 0;
            }
        }
    }

    // 모든 칸이 채워짐
    return 1;
}

int main() {
    // 입력
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    // 스도쿠 풀기
    solve();

    // 출력
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (j > 0) printf(" ");
            printf("%d", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}