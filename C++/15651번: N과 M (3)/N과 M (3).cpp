/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 15651                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/15651                          #+#        #+#      #+#    */
/*   Solved: 2025/11/24 14:53:25 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> sequence;

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
        sequence.push_back(i);

        backtrack(depth + 1);

        sequence.pop_back();
    }
}

int main() {
    cin >> N >> M;

    backtrack(0);

    return 0;
}