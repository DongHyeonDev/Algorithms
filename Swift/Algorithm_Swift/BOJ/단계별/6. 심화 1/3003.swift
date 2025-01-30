//
//  3003.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 1/30/25.
//

//  문제 링크: https://www.acmicpc.net/problem/3003
//  알고리즘 분류: 수학, 구현, 사칙연산

class BOJ3003: Solvable {
    // 메모리: 79512KB, 시간: 8ms, 코드 길이: 426B
    func run() {
        // 체스의 정규 피스 개수
        let correctPieces = [1, 1, 2, 2, 2, 8]

        // 입력 받기
        if let input = readLine() {
            let foundPieces = input.split(separator: " ").compactMap { Int($0) }
            
            // 각 피스에 대해 차이를 계산하여 출력
            let result = zip(correctPieces, foundPieces).map { $0 - $1 }
            
            // 결과 출력
            print(result.map { String($0) }.joined(separator: " "))
        }
    }
}
