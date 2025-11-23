/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 15650                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/15650                          #+#        #+#      #+#    */
/*   Solved: 2025/11/23 17:22:43 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> sequence;

void backtrack(int depth, int start) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            if (i > 0) cout << " ";
            cout << sequence[i];
        }
        cout << "\n";
        return;
    }

    for (int i = start; i <= N; i++) {
        sequence.push_back(i);

        backtrack(depth + 1, i + 1);

        sequence.pop_back();
    }
}

int main() {
    cin >> N >> M;

    backtrack(0, 1);

    return 0;
}