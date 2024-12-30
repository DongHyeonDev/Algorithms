//
//  10950.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 12/18/24.
//

//  문제 링크: https://www.acmicpc.net/problem/10950
//  알고리즘 분류: 구현, 사칙연산, 수학

class BOJ10950: Solvable {
    // 메모리: 79512KB, 시간: 8ms, 코드 길이: 937B
    func run() {
        // 입력 받기
        if let tInput = readLine(), let t = Int(tInput) {
            // 테스트 케이스 수만큼 반복
            for _ in 0..<t {
                if let input = readLine() {
                    let numbers = input.split(separator: " ").compactMap { Int($0) }
                    if numbers.count == 2 {
                        let a = numbers[0]
                        let b = numbers[1]
                        
                        // 조건 확인: 0 < A, B < 10
                        if a > 0 && b > 0 && a < 10 && b < 10 {
                            print(a + b)
                        } else {
                            print("입력 값은 0 초과 10 미만의 정수여야 합니다.")
                        }
                    } else {
                        print("두 개의 정수를 입력해주세요.")
                    }
                } else {
                    print("올바른 수를 입력해주세요.")
                }
            }
        } else {
            print("테스트 케이스의 갯수를 올바르게 입력해주세요.")
        }
    }
}
