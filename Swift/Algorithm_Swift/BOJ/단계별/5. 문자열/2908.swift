//
//  2908.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 1/28/25.
//

//  문제 링크: https://www.acmicpc.net/problem/2908
//  알고리즘 분류: 수학, 구현

class BOJ2908: Solvable {
    // 메모리: 79512KB, 시간: 12ms, 코드 길이: 401B
    func run() {
        // 입력 받기
        if let input = readLine() {
            // 입력을 공백으로 분리하여 두 숫자를 가져옴
            let numbers = input.split(separator: " ").map { String($0.reversed()) }
            
            // 숫자를 정수로 변환하여 비교
            if let number1 = Int(numbers[0]), let number2 = Int(numbers[1]) {
                print(max(number1, number2)) // 더 큰 숫자를 출력
            }
        }
    }
}
