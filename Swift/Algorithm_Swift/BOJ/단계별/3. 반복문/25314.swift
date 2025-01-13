//
//  25314.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 1/13/25.
//

//  문제 링크: https://www.acmicpc.net/problem/25314
//  알고리즘 분류: 구현

class BOJ25314: Solvable {
    // 메모리: 79508KB, 시간: 8ms, 코드 길이: 360B
    func run() {
        // 입력 받기
        if let input = readLine(), let n = Int(input), n % 4 == 0, n >= 4 {
            // "long"의 반복 횟수 계산
            let repeatCount = n / 4
            // "long"을 반복하고 마지막에 "int" 추가
            let result = Array(repeating: "long", count: repeatCount).joined(separator: " ") + " int"
            // 결과 출력
            print(result)
        }
    }
}
