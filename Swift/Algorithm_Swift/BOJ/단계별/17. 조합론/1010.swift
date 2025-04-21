//
//  1010.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 4/21/25.
//

//  문제 링크: https://www.acmicpc.net/problem/1010
//  알고리즘 분류: 수학, 다이나믹 프로그래밍, 조합론

class BOJ1010: Solvable {
    // 메모리: 79512KB, 시간: 8ms, 코드 길이: 543B
    func run() {
        // 입력 처리
        if let t = Int(readLine() ?? "") {
            for _ in 0..<t {
                let parts = readLine()!.split(separator: " ").compactMap { Int($0) }
                let N = parts[0]
                let M = parts[1]
                
                // 최적화를 위해 작은 쪽 k = min(N, M−N) 선택
                let k = min(N, M - N)
                var result = 1
                
                // C(M, N) = M×(M−1)×…×(M−k+1) / (1×2×…×k)
                for i in 0..<k {
                    result = result * (M - i) / (i + 1)
                }
                
                print(result)
            }
        }
    }
}
