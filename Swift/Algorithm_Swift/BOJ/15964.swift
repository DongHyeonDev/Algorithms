//
//  15964.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 1/3/25.
//

//  문제 링크: https://www.acmicpc.net/problem/15964
//  알고리즘 분류: 사칙연산, 수학, 구현

class BOJ15964: Solvable {
    // 메모리: 79512KB, 시간: 8ms, 코드 길이: 436B
    func run() {
        // 입력 받기
        if let input = readLine() {
            let numbers = input.split(separator: " ").compactMap { Int($0) }
            
            if numbers.count == 2 {
                let a = numbers[0]
                let b = numbers[1]
                
                // A＠B 계산
                let result = (a + b) * (a - b)
                
                // 결과 출력
                print(result)
            } else {
                print("정확히 두 개의 정수를 입력해주세요.")
            }
        }
    }
}
