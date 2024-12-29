//
//  10872.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 12/18/24.
//

//  문제 링크: https://www.acmicpc.net/problem/10872
//  알고리즘 분류: 구현, 수학

class BOJ10872: Solvable {
    func run() {
        // 팩토리얼 계산 함수
        func factorial(_ n: Int) -> Int {
            if n == 0 {
                return 1
            }
            return n * factorial(n - 1)
        }
        
        // 입력 받기
        if let input = readLine(), let n = Int(input) {
            // 조건 확인: 0 ≤ N ≤ 12
            if n >= 0 && n <= 12 {
                // 팩토리얼 계산 및 출력
                print(factorial(n))
            } else {
                print("입력 값은 0 이상 12 이하의 정수여야 합니다.")
            }
        } else {
            print("올바른 정수를 입력해주세요.")
        }
    }
}
