/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1992                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1992                           #+#        #+#      #+#    */
/*   Solved: 2025/12/28 16:53:20 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

char image[64][64];

// (x, y)에서 시작하는 size×size 영역이 모두 같은 값인지 확인
int check_same(int x, int y, int size) {
    char first = image[x][y];

    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (image[i][j] != first) {
                return -1;  // 섞여 있음
            }
        }
    }

    return first - '0';  // 0 또는 1 반환
}

// 쿼드트리 압축
void quad_tree(int x, int y, int size) {
    int result = check_same(x, y, size);

    if (result != -1) {
        // 모두 같은 값
        printf("%d", result);
        return;
    }

    // 섞여 있으면 4등분
    printf("(");

    int half = size / 2;
    quad_tree(x, y, half);                    // 좌상
    quad_tree(x, y + half, half);             // 우상
    quad_tree(x + half, y, half);             // 좌하
    quad_tree(x + half, y + half, half);      // 우하

    printf(")");
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%s", image[i]);
    }

    quad_tree(0, 0, N);
    printf("\n");

    return 0;
}