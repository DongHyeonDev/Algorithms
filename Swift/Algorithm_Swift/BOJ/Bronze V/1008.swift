//
//  1008.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 12/10/24.
//


class BOJ1008: Solvable {
    func run() {
        // 입력 받기
        if let input = readLine() {
            // 입력 문자열을 공백 기준으로 나누고 정수로 변환
            let numbers = input.split(separator: " ").compactMap { Double($0) }
            if numbers.count == 2 {
                let a = numbers[0]
                let b = numbers[1]
                
                // 조건 확인: 0 < A, B < 10
                if a > 0 && b > 0 && a < 10 && b < 10 {
                    // 출력
                    print(a / b)
                } else {
                    print("입력 값은 0보다 크고 10보다 작은 정수여야 합니다.")
                }
            } else {
                print("두 개의 정수를 입력해주세요.")
            }
        } else {
            print("입력이 잘못되었습니다.")
        }
    }
}
