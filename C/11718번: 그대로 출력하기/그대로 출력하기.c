/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 11718                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/11718                          #+#        #+#      #+#    */
/*   Solved: 2025/06/08 16:47:14 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int main() {
    char line[101];
    // EOF(입력 끝)까지 한 줄씩 읽어 그대로 출력
    while (fgets(line, sizeof(line), stdin)) {
        fputs(line, stdout);
    }
    return 0;
}