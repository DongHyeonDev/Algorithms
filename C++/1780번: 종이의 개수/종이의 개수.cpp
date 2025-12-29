/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1780                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1780                           #+#        #+#      #+#    */
/*   Solved: 2025/12/29 09:55:44 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>

using namespace std;

int paper[2200][2200];
int count_minus = 0;  // -1 개수
int count_zero = 0;   // 0 개수
int count_plus = 0;   // 1 개수

// (x, y)에서 시작하는 size×size 영역이 모두 같은 수인지 확인
int check_same(int x, int y, int size) {
    int first = paper[x][y];

    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (paper[i][j] != first) {
                return 2;  // 다른 수가 섞여 있음
            }
        }
    }

    return first;  // -1, 0, 또는 1 반환
}

// 분할 정복
void divide_and_conquer(int x, int y, int size) {
    int result = check_same(x, y, size);

    if (result != 2) {
        // 모두 같은 수
        if (result == -1) {
            count_minus++;
        } else if (result == 0) {
            count_zero++;
        } else {
            count_plus++;
        }
        return;
    }

    // 9등분하여 재귀 호출
    int third = size / 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            divide_and_conquer(x + i * third, y + j * third, third);
        }
    }
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> paper[i][j];
        }
    }

    divide_and_conquer(0, 0, N);

    cout << count_minus << "\n" << count_zero << "\n" << count_plus << "\n";

    return 0;
}