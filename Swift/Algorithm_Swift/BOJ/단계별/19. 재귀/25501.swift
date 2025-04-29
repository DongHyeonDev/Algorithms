//
//  25501.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 4/29/25.
//

//  문제 링크: https://www.acmicpc.net/problem/25501
//  알고리즘 분류: 구현, 문자열, 재귀

class BOJ25501: Solvable {
    // 메모리: 79508KB, 시간: 56ms, 코드 길이: 918B
    func run() {
        // 전역 변수로 재귀 호출 횟수 카운트
        var callCount = 0

        // 재귀 함수: s[l...r]이 팰린드롬인지 확인하며 호출 횟수를 센다.
        func recursion(_ s: [Character], _ l: Int, _ r: Int) -> Int {
            callCount += 1
            if l >= r {
                return 1
            } else if s[l] != s[r] {
                return 0
            } else {
                return recursion(s, l + 1, r - 1)
            }
        }

        // isPalindrome: 전체 문자열에 대해 recursion을 호출하고 결과와 호출 횟수를 반환
        func isPalindrome(_ s: String) -> (result: Int, calls: Int) {
            callCount = 0
            let chars = Array(s)
            let res = recursion(chars, 0, chars.count - 1)
            return (res, callCount)
        }

        // 입력 및 처리
        if let line = readLine(), let T = Int(line) {
            for _ in 0..<T {
                if let s = readLine() {
                    let (result, calls) = isPalindrome(s)
                    print("\(result) \(calls)")
                }
            }
        }
    }
}
