/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 27433                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/27433                          #+#        #+#      #+#    */
/*   Solved: 2025/11/15 23:43:56 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

long long factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    
    return n * factorial(n - 1);
}

int main() {
    int n;
    scanf("%d", &n);
    
    printf("%lld\n", factorial(n));
    
    return 0;
}