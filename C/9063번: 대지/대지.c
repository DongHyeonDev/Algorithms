/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 9063                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/9063                           #+#        #+#      #+#    */
/*   Solved: 2025/09/10 12:27:44 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int x, y;
    scanf("%d %d", &x, &y);
    int minX = x;
    int maxX = x;
    int minY = y;
    int maxY = y;

    for (int i = 1; i < n; ++i) {
        scanf("%d %d", &x, &y);
        if (x < minX) minX = x;
        if (x > maxX) maxX = x;
        if (y < minY) minY = y;
        if (y > maxY) maxY = y;
    }

    long long width  = (long long)maxX - minX;
    long long height = (long long)maxY - minY;
    long long area   = width * height;

    printf("%lld\n", area);
    return 0;
}