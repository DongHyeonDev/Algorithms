//
//  2588.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 1/7/25.
//

//  문제 링크: https://www.acmicpc.net/problem/2588
//  알고리즘 분류: 수학, 사칙연산

class BOJ2588: Solvable {
    // 메모리: 79508KB, 시간: 12ms, 코드 길이: 608B
    func run() {
        // 입력 받기
        if let firstInput = readLine(), let secondInput = readLine() {
            if let num1 = Int(firstInput), let num2 = Int(secondInput) {
                // 각 자리별 곱셈
                let onesPlace = num2 % 10
                let tensPlace = (num2 / 10) % 10
                let hundredsPlace = num2 / 100
                
                let result1 = num1 * onesPlace
                let result2 = num1 * tensPlace
                let result3 = num1 * hundredsPlace
                let finalResult = num1 * num2
                
                // 출력
                print(result1)
                print(result2)
                print(result3)
                print(finalResult)
            }
        }
    }
}
