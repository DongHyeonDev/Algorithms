//
//  1330.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 12/15/24.
//

//  문제 링크: https://www.acmicpc.net/problem/1330
//  알고리즘 분류: 구현

class BOJ1330: Solvable {
    func run() {
        // 입력 받기
        if let input = readLine() {
            // 입력 문자열을 공백 기준으로 나누고 정수로 변환
            let numbers = input.split(separator: " ").compactMap { Int($0) }
            if numbers.count == 2 {
                let a = numbers[0]
                let b = numbers[1]
                
                // 조건 확인: -10,000 <= A, B <= 10,000
                if a >= -10000 && b >= -10000 && a <= 10000 && b <= 10000 {
                    if a < b {
                        print("<")
                    } else if a == b {
                        print("==")
                    } else {
                        print(">")
                    }
                } else {
                    print("입력 값은 -10,000보다 크거나 같고 10,000보다 작거나 같은 정수여야 합니다.")
                }
            } else {
                print("두 개의 정수를 입력해주세요.")
            }
        } else {
            print("입력이 잘못되었습니다.")
        }
    }
}
