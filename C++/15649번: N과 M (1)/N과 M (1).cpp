/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 15649                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/15649                          #+#        #+#      #+#    */
/*   Solved: 2025/11/22 16:21:24 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> sequence;
vector<bool> visited;

void backtrack(int depth) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            if (i > 0) cout << " ";
            cout << sequence[i];
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (visited[i]) continue;

        sequence.push_back(i);
        visited[i] = true;

        backtrack(depth + 1);

        sequence.pop_back();
        visited[i] = false;
    }
}

int main() {
    cin >> N >> M;
    visited.assign(N + 1, false);

    backtrack(0);

    return 0;
}