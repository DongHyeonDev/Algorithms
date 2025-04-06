//
//  13909.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 4/6/25.
//

//  문제 링크: https://www.acmicpc.net/problem/13909
//  알고리즘 분류: 수학, 정수론

class BOJ13909: Solvable {
    // 메모리: 79508KB, 시간: 8ms, 코드 길이: 190B
    func run() {
        if let line = readLine(), let n = Int(line) {
            // 1부터 n까지의 완전 제곱수 개수는 sqrt(n)
            let result = Int(Double(n).squareRoot())
            print(result)
        }
    }
}
