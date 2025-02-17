//
//  5086.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 2/16/25.
//

//  문제 링크: https://www.acmicpc.net/problem/5086
//  알고리즘 분류: 수학, 사칙연산

class BOJ5086: Solvable {
    // 메모리: 79512KB, 시간: 8ms, 코드 길이: 491B
    func run() {
        while let input = readLine()?.split(separator: " ").compactMap({ Int($0) }) {
            let a = input[0]
            let b = input[1]

            // 종료 조건
            if a == 0 && b == 0 {
                break
            }

            // 약수인지 확인 (a가 b의 약수인지)
            if b % a == 0 {
                print("factor")
            }
            // 배수인지 확인 (a가 b의 배수인지)
            else if a % b == 0 {
                print("multiple")
            }
            // 둘 다 아닌 경우
            else {
                print("neither")
            }
        }
    }
}
