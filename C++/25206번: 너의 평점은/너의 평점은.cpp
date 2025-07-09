/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 25206                             :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: dhkim0206 <boj.kr/u/dhkim0206>              +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/25206                          #+#        #+#      #+#    */
/*   Solved: 2025/07/09 22:34:54 by dhkim0206     ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <iomanip>
#include <string>

// 등급을 과목평점으로 변환하는 함수
double getGradePoint(const std::string& grade) {
    if (grade == "A+") return 4.5;
    if (grade == "A0") return 4.0;
    if (grade == "B+") return 3.5;
    if (grade == "B0") return 3.0;
    if (grade == "C+") return 2.5;
    if (grade == "C0") return 2.0;
    if (grade == "D+") return 1.5;
    if (grade == "D0") return 1.0;
    if (grade == "F")  return 0.0;
    return -1.0; // P인 경우
}

int main() {
    double totalScore = 0.0;
    double totalCredit = 0.0;

    for (int i = 0; i < 20; ++i) {
        std::string subject, grade;
        double credit;
        std::cin >> subject >> credit >> grade;

        double point = getGradePoint(grade);
        if (point >= 0.0) { // P는 제외
            totalScore += credit * point;
            totalCredit += credit;
        }
    }

    std::cout << std::fixed << std::setprecision(6);
    std::cout << (totalCredit > 0 ? totalScore / totalCredit : 0.0) << "\n";

    return 0;
}