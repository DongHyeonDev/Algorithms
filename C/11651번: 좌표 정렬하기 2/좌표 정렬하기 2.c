/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11651                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11651                          #+#        #+#      #+#    */
/*   Solved: 2025/10/04 12:16:48 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Point;

int compare(const void *a, const void *b) {
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;

    if (p1->y == p2->y) {
        return p1->x - p2->x;
    }
    return p1->y - p2->y;
}

int main() {
    int n;
    scanf("%d", &n);

    Point *points = (Point *)malloc(n * sizeof(Point));
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    qsort(points, n, sizeof(Point), compare);

    for (int i = 0; i < n; i++) {
        printf("%d %d\n", points[i].x, points[i].y);
    }

    free(points);
    return 0;
}