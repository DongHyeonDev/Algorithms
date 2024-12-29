//
//  2753.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 12/16/24.
//

//  문제 링크: https://www.acmicpc.net/problem/2753
//  알고리즘 분류: 구현, 사칙연산, 수학

class BOJ2753: Solvable {
    func run() {
        // 연도 입력 받기
        if let yearInput = readLine(), let year = Int(yearInput) {
            // 조건 확인: 1 <= year <= 4,000
            if year >= 1 && year <= 4000 {
                // 윤년 조건 확인 4의 배수이면서 100의 배수가 아닌 조건
                if year % 4 == 0 && year % 100 != 0 {
                    print(1) // 윤년
                } else if year % 400 == 0 {
                    print(1) // 윤년
                } else {
                    print(0) // 윤년 아님
                }
            } else {
                print("연도는 1보다 크거나 같고 4,000보다 작거나 같은 정수여야 합니다.")
            }
        } else {
            print("연도를 올바르게 입력해주세요.")
        }
    }
}
