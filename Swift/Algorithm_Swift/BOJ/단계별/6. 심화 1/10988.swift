//
//  10988.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 2/1/25.
//

//  문제 링크: https://www.acmicpc.net/problem/10988
//  알고리즘 분류: 구현, 문자열

class BOJ10988: Solvable {
    // 메모리: 79504KB, 시간: 8ms, 코드 길이: 214B
    func run() {
        // 입력 받기
        if let input = readLine() {
            // 문자열을 뒤집어서 원래 문자열과 비교
            let isPalindrome = input == String(input.reversed()) ? 1 : 0
            print(isPalindrome)
        }
    }
}
