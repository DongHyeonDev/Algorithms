//
//  2475.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 1/4/25.
//

//  문제 링크: https://www.acmicpc.net/problem/2475
//  알고리즘 분류: 구현, 사칙연산, 수학

class BOJ2475: Solvable {
    // 메모리: 79512KB, 시간: 8ms, 코드 길이: 570B
    func run() {
        // 입력 받기
        if let input = readLine() {
            let numbers = input.split(separator: " ").compactMap { Int($0) }
            
            // 입력된 숫자가 정확히 5개인지 확인
            if numbers.count == 5 {
                // 각 숫자를 제곱한 후 합산
                let sumOfSquares = numbers.reduce(0) { $0 + $1 * $1 }
                
                // 검증수 계산
                let verificationNumber = sumOfSquares % 10
                
                // 결과 출력
                print(verificationNumber)
            } else {
                print("정확히 5개의 숫자를 입력해주세요.")
            }
        }
    }
}
