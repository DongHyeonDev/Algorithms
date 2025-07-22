/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2563                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2563                           #+#        #+#      #+#    */
/*   Solved: 2025/07/22 22:35:21 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdbool.h>

int main() {
    int N;
    scanf("%d", &N);

    bool paper[100][100] = { false };

    for (int n = 0; n < N; n++) {
        int x, y;
        scanf("%d %d", &x, &y);
        
        for (int i = x; i < x + 10; i++) {
            for (int j = y; j < y + 10; j++) {
                paper[i][j] = true;
            }
        }
    }

    int area = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (paper[i][j]) {
                area++;
            }
        }
    }

    printf("%d\n", area);
    return 0;
}