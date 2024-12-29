//
//  2754.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 12/29/24.
//

//  문제 링크: https://www.acmicpc.net/problem/2754
//  알고리즘 분류: 구현, 문자열

class BOJ2754: Solvable {
    func run() {
        // 성적과 평점 매핑
        let gradeToPoint: [String: Double] = [
            "A+": 4.3, "A0": 4.0, "A-": 3.7,
            "B+": 3.3, "B0": 3.0, "B-": 2.7,
            "C+": 2.3, "C0": 2.0, "C-": 1.7,
            "D+": 1.3, "D0": 1.0, "D-": 0.7,
            "F": 0.0
        ]

        // 입력 받기
        if let input = readLine(), let point = gradeToPoint[input] {
            // 평점 출력
            print(String(format: "%.1f", point))
        } else {
            print("잘못된 입력입니다.")
        }
    }
}
