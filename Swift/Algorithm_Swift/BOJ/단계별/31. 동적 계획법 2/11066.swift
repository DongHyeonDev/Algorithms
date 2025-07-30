//
//  11066.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 7/30/25.
//

//  문제 링크: https://www.acmicpc.net/problem/11066
//  알고리즘 분류: 다이나믹 프로그래밍

class BOJ11066: Solvable {
    // 메모리: 81492KB, 시간: 1892ms, 코드 길이: 756B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()
        let T = fileIO.readInt()
        var dp = [[Int]](repeating: [Int](repeating: 0, count: 501), count: 501)
        var prefixSum = [Int](repeating: 0, count: 501)

        for _ in 0..<T {
            let K = fileIO.readInt()
            var file = [Int](repeating: 0, count: K + 1)
            
            for i in 1...K {
                file[i] = fileIO.readInt()
                prefixSum[i] = prefixSum[i - 1] + file[i]
            }

            for len in 2...K {
                for from in 1...(K - len + 1) {
                    let to = from + len - 1
                    dp[from][to] = Int.max
                    for mid in from..<to {
                        dp[from][to] = min(dp[from][to], dp[from][mid] + dp[mid+1][to] + prefixSum[to] - prefixSum[from-1])
                    }
                }
            }

            print(dp[1][K])
        }
    }
}
