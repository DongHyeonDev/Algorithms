//
//  25206.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 2/5/25.
//

//  문제 링크: https://www.acmicpc.net/problem/25206
//  알고리즘 분류: 구현, 문자열

class BOJ25206: Solvable {
    // 메모리: 79508KB, 시간: 8ms, 코드 길이: 1014B
    func run() {
        // 성적 등급과 평점 매핑
        let gradeToPoint: [String: Double] = [
            "A+": 4.5,
            "A0": 4.0,
            "B+": 3.5,
            "B0": 3.0,
            "C+": 2.5,
            "C0": 2.0,
            "D+": 1.5,
            "D0": 1.0,
            "F": 0.0,
            "P": -1.0 // P는 계산에서 제외
        ]

        // 총 평점 계산을 위한 변수
        var totalScore = 0.0  // (학점 × 평점)의 합
        var totalCredits = 0.0  // 유효한 학점 총합

        // 20줄 입력 받기
        for _ in 0..<20 {
            if let input = readLine() {
                let components = input.split(separator: " ")
                let credit = Double(components[1]) ?? 0.0
                let grade = String(components[2])
                
                // P 등급 제외하고 계산
                if let gradePoint = gradeToPoint[grade], gradePoint != -1.0 {
                    totalScore += credit * gradePoint
                    totalCredits += credit
                }
            }
        }

        // 전공 평점 계산 및 출력
        let gpa = totalCredits > 0 ? totalScore / totalCredits : 0.0
        print(String(format: "%.6f", gpa))  // 소수점 6자리까지 출력
    }
}
