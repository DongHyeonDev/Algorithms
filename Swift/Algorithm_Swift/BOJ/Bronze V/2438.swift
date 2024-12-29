//
//  2438.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 12/21/24.
//


class BOJ2438: Solvable {
    func run() {
        // 입력 받기
        if let input = readLine(), let n = Int(input) {
            // 조건 확인: 1 ≤ N ≤ 100
            if n >= 1 && n <= 100 {
                // 별 출력
                for i in 1...n {
                    print(String(repeating: "*", count: i))
                }
            } else {
                print("입력 값은 1 이상 100 이하의 정수여야 합니다.")
            }
        } else {
            print("올바른 정수를 입력해주세요.")
        }
    }
}
