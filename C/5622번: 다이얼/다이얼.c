/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 5622                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/5622                           #+#        #+#      #+#    */
/*   Solved: 2025/06/06 22:48:43 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    scanf("%s", str);
    
    int total_time = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= 'A' && str[i] <= 'C') {
            total_time += 3;
        } else if (str[i] >= 'D' && str[i] <= 'F') {
            total_time += 4;
        } else if (str[i] >= 'G' && str[i] <= 'I') {
            total_time += 5;
        } else if (str[i] >= 'J' && str[i] <= 'L') {
            total_time += 6;
        } else if (str[i] >= 'M' && str[i] <= 'O') {
            total_time += 7;
        } else if (str[i] >= 'P' && str[i] <= 'S') {
            total_time += 8;
        } else if (str[i] >= 'T' && str[i] <= 'V') {
            total_time += 9;
        } else if (str[i] >= 'W' && str[i] <= 'Z') {
            total_time += 10;
        }
    }
    
    printf("%d\n", total_time);
    return 0;
}