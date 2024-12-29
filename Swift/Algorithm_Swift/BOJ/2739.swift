//
//  2739.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 12/20/24.
//

//  문제 링크: https://www.acmicpc.net/problem/2739
//  알고리즘 분류: 구현, 수학

class BOJ2739: Solvable {
    func run() {
        // 입력 받기
        if let input = readLine(), let n = Int(input) {
            // 조건 확인: 1 ≤ N ≤ 9
            if n >= 1 && n <= 9 {
                // 구구단 출력
                for i in 1...9 {
                    print("\(n) * \(i) = \(n * i)")
                }
            } else {
                print("입력 값은 1 이상 9 이하의 정수여야 합니다.")
            }
        } else {
            print("올바른 정수를 입력해주세요.")
        }
    }
}
