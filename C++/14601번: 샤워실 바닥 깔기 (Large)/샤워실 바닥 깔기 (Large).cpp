/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 14601                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/14601                          #+#        #+#      #+#    */
/*   Solved: 2026/04/16 14:54:34 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
using namespace std;

int SIZE;
vector<vector<int>> grid;
int tileNum = 0;

void solve(int r, int c, int sz, int sr, int sc) {
    if (sz == 1) return;
    int t = ++tileNum;
    int half = sz / 2;
    int mr = r + half, mc = c + half;
    bool inTop = sr < mr, inLeft = sc < mc;

    if (!(inTop  && inLeft))  grid[mr-1][mc-1] = t;
    if (!(inTop  && !inLeft)) grid[mr-1][mc]   = t;
    if (!(!inTop && inLeft))  grid[mr][mc-1]   = t;
    if (!(!inTop && !inLeft)) grid[mr][mc]     = t;

    solve(r,  c,  half, inTop&&inLeft   ? sr:mr-1, inTop&&inLeft   ? sc:mc-1);
    solve(r,  mc, half, inTop&&!inLeft  ? sr:mr-1, inTop&&!inLeft  ? sc:mc  );
    solve(mr, c,  half, !inTop&&inLeft  ? sr:mr,   !inTop&&inLeft  ? sc:mc-1);
    solve(mr, mc, half, !inTop&&!inLeft ? sr:mr,   !inTop&&!inLeft ? sc:mc  );
}

int main() {
    int K, x, y; cin >> K >> x >> y;
    SIZE = 1 << K;
    grid.assign(SIZE, vector<int>(SIZE, 0));

    int dr = SIZE - y, dc = x - 1;
    grid[dr][dc] = -1;
    solve(0, 0, SIZE, dr, dc);

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (j) cout << " ";
            cout << grid[i][j];
        }
        cout << "\n";
    }
    return 0;
}