/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2667                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2667                           #+#        #+#      #+#    */
/*   Solved: 2026/01/22 14:01:33 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int N;
char map[26][27];
int visited[26][26];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int dfs(int x, int y) {
    visited[x][y] = 1;
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

int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%s", map[i]);
    }
    
    int complexes[625];
    int complex_count = 0;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == '1' && !visited[i][j]) {
                int size = dfs(i, j);
                complexes[complex_count++] = size;
            }
        }
    }
    
    qsort(complexes, complex_count, sizeof(int), compare);
    
    printf("%d\n", complex_count);
    for (int i = 0; i < complex_count; i++) {
        printf("%d\n", complexes[i]);
    }
    
    return 0;
}