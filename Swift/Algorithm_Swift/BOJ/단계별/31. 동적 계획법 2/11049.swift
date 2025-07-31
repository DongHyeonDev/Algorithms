//
//  11049.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 7/31/25.
//

//  문제 링크: https://www.acmicpc.net/problem/11049
//  알고리즘 분류: 다이나믹 프로그래밍

class BOJ11049: Solvable {
    // 메모리: 81492KB, 시간: 732ms, 코드 길이: 609B
    func run() {
        // 빠른 입출력 설정
        let fileIO = RhynoFileIO()
        let N = fileIO.readInt()
        var size = [(Int, Int)](repeating: (0, 0), count: N + 1)

        for i in 1...N {
            let r = fileIO.readInt()
            let c = fileIO.readInt()
            size[i] = (r, c)
        }

        var dp = [[Int]](repeating: [Int](repeating: 0, count: N + 1), count: N + 1)

        for len in 2...N {
            for i in 1...(N - len + 1) {
                let j = i + len - 1
                dp[i][j] = Int.max
                for k in i..<j {
                    let cost = dp[i][k] + dp[k+1][j] + size[i].0 * size[k].1 * size[j].1
                    dp[i][j] = min(dp[i][j], cost)
                }
            }
        }

        print(dp[1][N])
    }
}
