/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9019                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9019                           #+#        #+#      #+#    */
/*   Solved: 2026/03/01 11:00:29 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

const int MAX = 10000;

int applyD(int n) { return (n * 2) % 10000; }
int applyS(int n) { return n == 0 ? 9999 : n - 1; }
int applyL(int n) { return (n % 1000) * 10 + n / 1000; }
int applyR(int n) { return (n % 10) * 1000 + n / 10; }

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int A, B;
        cin >> A >> B;
        
        vector<int>  dist(MAX, -1);
        vector<int>  from(MAX, -1);
        vector<char> op(MAX, ' ');   // 어떤 명령어로 왔는지
        
        queue<int> q;
        dist[A] = 0;
        q.push(A);
        
        while (!q.empty()) {
            int x = q.front(); q.pop();
            if (x == B) break;
            
            // D, S, L, R 순서로 탐색
            vector<pair<int,char>> moves = {
                {applyD(x), 'D'},
                {applyS(x), 'S'},
                {applyL(x), 'L'},
                {applyR(x), 'R'}
            };
            for (auto [nx, cmd] : moves) {
                if (dist[nx] != -1) continue;
                dist[nx] = dist[x] + 1;
                from[nx] = x;
                op[nx]   = cmd;
                q.push(nx);
            }
        }
        
        // 역추적: B → A 방향으로 op 수집
        string result;
        int cur = B;
        while (cur != A) {
            result += op[cur];
            cur = from[cur];
        }
        reverse(result.begin(), result.end());
        cout << result << "\n";
    }
    
    return 0;
}