/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 1085                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/1085                           #+#        #+#      #+#    */
/*   Solved: 2025/09/06 11:16:04 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int main() {
    int x, y, w, h;
    if (scanf("%d %d %d %d", &x, &y, &w, &h) != 4) return 0;

    int dist_left = x;
    int dist_right = w - x;
    int dist_bottom = y;
    int dist_top = h - y;

    int min_dist = dist_left;
    if (dist_right < min_dist) min_dist = dist_right;
    if (dist_bottom < min_dist) min_dist = dist_bottom;
    if (dist_top < min_dist) min_dist = dist_top;

    printf("%d\n", min_dist);
    return 0;
}