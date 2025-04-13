/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 25304                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/25304                          #+#        #+#      #+#    */
/*   Solved: 2025/04/13 22:30:50 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int sum = 0;
    for (int i = 0; i < M; i++) {
        int price, count;
        scanf("%d %d", &price, &count);
        sum += price * count;
    }

    if (sum == N) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}