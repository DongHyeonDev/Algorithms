/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2667                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2667                           #+#        #+#      #+#    */
/*   Solved: 2026/01/22 14:01:42 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N;
string map[26];
bool visited[26][26];
int dx[] = {-1, 1, 0, 0};  // 상, 하, 좌, 우
int dy[] = {0, 0, -1, 1};

int dfs(int x, int y) {
    visited[x][y] = true;
    int count = 1;
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
            if (map[nx][ny] == '1' && !visited[nx][ny]) {
                count += dfs(nx, ny);
            }
        }
    }
    
    return count;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> map[i];
    }
    
    vector<int> complexes;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == '1' && !visited[i][j]) {
                int size = dfs(i, j);
                complexes.push_back(size);
            }
        }
    }
    
    sort(complexes.begin(), complexes.end());
    
    cout << complexes.size() << "\n";
    for (int size : complexes) {
        cout << size << "\n";
    }
    
    return 0;
}