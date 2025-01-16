//
//  2439.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 1/16/25.
//

//  문제 링크: https://www.acmicpc.net/problem/2439
//  알고리즘 분류: 구현

class BOJ2439: Solvable {
    // 메모리: 79508KB, 시간: 8ms, 코드 길이: 334B
    func run() {
        // 입력 받기
        if let input = readLine(), let n = Int(input) {
            for i in 1...n {
                // 공백과 별의 개수 계산
                let spaces = String(repeating: " ", count: n - i)
                let stars = String(repeating: "*", count: i)
                // 출력 형식: 공백 + 별
                print(spaces + stars)
            }
        }
    }
}
