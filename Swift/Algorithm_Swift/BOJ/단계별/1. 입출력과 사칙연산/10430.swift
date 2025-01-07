//
//  10430.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 1/7/25.
//

//  문제 링크: https://www.acmicpc.net/problem/10430
//  알고리즘 분류: 수학, 구현, 사칙연산

class BOJ10430: Solvable {
    // 메모리: 79512KB, 시간: 8ms, 코드 길이: 589B
    func run() {
        // 입력 받기
        if let input = readLine() {
            let numbers = input.split(separator: " ").compactMap { Int($0) }
            
            // A, B, C 추출
            if numbers.count == 3 {
                let A = numbers[0]
                let B = numbers[1]
                let C = numbers[2]
                
                // 계산
                let result1 = (A + B) % C
                let result2 = ((A % C) + (B % C)) % C
                let result3 = (A * B) % C
                let result4 = ((A % C) * (B % C)) % C
                
                // 결과 출력
                print(result1)
                print(result2)
                print(result3)
                print(result4)
            }
        }
    }
}
