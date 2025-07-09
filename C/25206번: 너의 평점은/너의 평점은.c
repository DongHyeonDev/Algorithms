/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 25206                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/25206                          #+#        #+#      #+#    */
/*   Solved: 2025/07/09 22:34:40 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

int main() {
    double total_score = 0.0;
    double total_credits = 0.0;
    
    for (int i = 0; i < 20; i++) {
        char name[51];
        double credit;
        char grade[3];
        
        scanf("%50s %lf %2s", name, &credit, grade);
        
        double point;
        if      (strcmp(grade, "A+") == 0) point = 4.5;
        else if (strcmp(grade, "A0") == 0) point = 4.0;
        else if (strcmp(grade, "B+") == 0) point = 3.5;
        else if (strcmp(grade, "B0") == 0) point = 3.0;
        else if (strcmp(grade, "C+") == 0) point = 2.5;
        else if (strcmp(grade, "C0") == 0) point = 2.0;
        else if (strcmp(grade, "D+") == 0) point = 1.5;
        else if (strcmp(grade, "D0") == 0) point = 1.0;
        else if (strcmp(grade, "F")  == 0) point = 0.0;
        else /* "P" */                continue;
        
        total_score   += credit * point;
        total_credits += credit;
    }
    
    printf("%.6f\n", total_score / total_credits);
    return 0;
}