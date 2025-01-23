//
//  1546.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 1/23/25.
//

//  문제 링크: https://www.acmicpc.net/problem/1546
//  알고리즘 분류: 수학, 사칙연산

class BOJ1546: Solvable {
    // 메모리: 79512KB, 시간: 8ms, 코드 길이: 485B
    func run() {
        // 입력 받기
        if let nInput = readLine(), let n = Int(nInput),
           let scoresInput = readLine() {
            let scores = scoresInput.split(separator: " ").compactMap { Double($0) }
            
            if let maxScore = scores.max() {
                // 점수 조작
                let adjustedScores = scores.map { $0 / maxScore * 100 }
                // 새로운 평균 계산
                let newAverage = adjustedScores.reduce(0, +) / Double(n)
                // 결과 출력
                print(newAverage)
            }
        }
    }
}
