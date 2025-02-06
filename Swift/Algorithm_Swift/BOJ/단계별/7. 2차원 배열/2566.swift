//
//  2566.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 2/6/25.
//

//  문제 링크: https://www.acmicpc.net/problem/2566
//  알고리즘 분류: 사칙연산, 구현, 수학

class BOJ2566: Solvable {
    // 메모리: 79772KB, 시간: 16ms, 코드 길이: 1787B
    func run() {
        var matrix: [[Int]] = []
        var maxNumber = Int.min
        var maxRow = 0
        var maxCol = 0

        // 9×9 행렬 입력 받기
        for _ in 0..<9 {
            if let input = readLine() {
                let row = input.split(separator: " ").compactMap { Int($0) }
                matrix.append(row)
            }
        }

        // 2차원 배열에서 최댓값 및 위치 찾기
        for row in 0..<9 {
            for col in 0..<9 {
                if matrix[row][col] > maxNumber {
                    maxNumber = matrix[row][col]
                    maxRow = row + 1  // 1-based index 변환
                    maxCol = col + 1  // 1-based index 변환
                }
            }
        }

        // 결과 출력
        print(maxNumber)
        print("\(maxRow) \(maxCol)")
    }
}
