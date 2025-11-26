/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9663                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9663                           #+#        #+#      #+#    */
/*   Solved: 2025/11/26 11:54:30 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
int count_result = 0;
vector<int> cols;

bool is_safe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (cols[i] == col) {
            return false;
        }

        if (abs(cols[i] - col) == abs(i - row)) {
            return false;
        }
    }

    return true;
}

void backtrack(int row) {
    if (row == N) {
        count_result++;
        return;
    }

    for (int col = 0; col < N; col++) {
        if (is_safe(row, col)) {
            cols[row] = col;

            backtrack(row + 1);
        }
    }
}

int main() {
    cin >> N;
    cols.resize(N);

    backtrack(0);

    cout << count_result << "\n";

    return 0;
}