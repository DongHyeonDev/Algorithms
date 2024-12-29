//
//  10951.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 12/21/24.
//


class BOJ10951: Solvable {
    func run() {
        while let input = readLine() {
            // 입력 문자열을 공백으로 나누어 숫자로 변환
            let numbers = input.split(separator: " ").compactMap { Int($0) }
            
            // 두 숫자가 있는지 확인
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
        }
    }
}
