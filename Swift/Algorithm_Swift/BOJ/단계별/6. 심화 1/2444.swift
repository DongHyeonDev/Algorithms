//
//  2444.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 1/31/25.
//

//  문제 링크: https://www.acmicpc.net/problem/2444
//  알고리즘 분류: 구현

class BOJ2444: Solvable {
    // 메모리: 79508KB, 시간: 12ms, 코드 길이: 562B
    func run() {
        // 입력 받기
        if let input = readLine(), let n = Int(input) {
            // 위쪽 삼각형 (1~N번째 줄)
            for i in 1...n {
                let spaces = String(repeating: " ", count: n - i)
                let stars = String(repeating: "*", count: 2 * i - 1)
                print(spaces + stars)
            }
            
            // 아래쪽 삼각형 (N+1~2N-1번째 줄)
            for i in stride(from: n-1, through: 1, by: -1) {
                let spaces = String(repeating: " ", count: n - i)
                let stars = String(repeating: "*", count: 2 * i - 1)
                print(spaces + stars)
            }
        }
    }
}
