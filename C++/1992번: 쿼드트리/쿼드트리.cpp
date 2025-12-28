/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1992                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1992                           #+#        #+#      #+#    */
/*   Solved: 2025/12/28 16:53:28 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <string>

using namespace std;

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
string quad_tree(int x, int y, int size) {
    int result = check_same(x, y, size);

    if (result != -1) {
        // 모두 같은 값
        return to_string(result);
    }

    // 섞여 있으면 4등분
    int half = size / 2;
    string str = "(";
    str += quad_tree(x, y, half);                    // 좌상
    str += quad_tree(x, y + half, half);             // 우상
    str += quad_tree(x + half, y, half);             // 좌하
    str += quad_tree(x + half, y + half, half);      // 우하
    str += ")";

    return str;
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> image[i];
    }

    cout << quad_tree(0, 0, N) << "\n";

    return 0;
}