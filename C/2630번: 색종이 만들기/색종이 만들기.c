/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2630                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2630                           #+#        #+#      #+#    */
/*   Solved: 2025/12/27 12:33:16 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int paper[128][128];
int white_count = 0;
int blue_count = 0;

// (x, y)에서 시작하는 size×size 영역이 모두 같은 색인지 확인
int is_same_color(int x, int y, int size) {
    int first_color = paper[x][y];

    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (paper[i][j] != first_color) {
                return -1;  // 다른 색이 섞여 있음
            }
        }
    }

    return first_color;  // 0 (흰색) 또는 1 (파란색)
}

// 분할 정복
void divide_and_conquer(int x, int y, int size) {
    int color = is_same_color(x, y, size);

    if (color != -1) {
        // 모두 같은 색
        if (color == 0) {
            white_count++;
        } else {
            blue_count++;
        }
        return;
    }

    // 4등분하여 재귀 호출
    int half = size / 2;
    divide_and_conquer(x, y, half);                    // 좌상
    divide_and_conquer(x, y + half, half);             // 우상
    divide_and_conquer(x + half, y, half);             // 좌하
    divide_and_conquer(x + half, y + half, half);      // 우하
}

int main() {
    int N;
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &paper[i][j]);
        }
    }

    divide_and_conquer(0, 0, N);

    printf("%d\n%d\n", white_count, blue_count);

    return 0;
}