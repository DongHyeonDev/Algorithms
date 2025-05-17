//
//  1149.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 5/17/25.
//

//  문제 링크: https://www.acmicpc.net/problem/1149
//  알고리즘 분류: 다이나믹 프로그래밍

class BOJ1149: Solvable {
    // 메모리: 79516KB, 시간: 8ms, 코드 길이: 1117B
    func run() {
        // 입력 수 처리
        let N = Int(readLine()!)!             // 집의 개수 (2 ≤ N ≤ 1000)

        // dp[i][c]: i번째 집을 색 c(0:빨강,1:초록,2:파랑)으로 칠했을 때의 최소 누적 비용
        var dp = [[Int]](repeating: [0, 0, 0], count: N)

        for i in 0..<N {
            // i번째 집을 빨강·초록·파랑으로 칠하는 비용
            let cost = readLine()!.split(separator: " ").map { Int($0)! }
            
            if i == 0 {
                // 첫 집은 그냥 그 비용 그대로
                dp[0] = cost
            } else {
                // 빨강으로 칠할 경우, 이전 집을 초록/파랑 중 최소로 칠해야 함
                dp[i][0] = cost[0] + min(dp[i-1][1], dp[i-1][2])
                // 초록으로 칠할 경우, 이전 집을 빨강/파랑 중 최소로 칠해야 함
                dp[i][1] = cost[1] + min(dp[i-1][0], dp[i-1][2])
                // 파랑으로 칠할 경우, 이전 집을 빨강/초록 중 최소로 칠해야 함
                dp[i][2] = cost[2] + min(dp[i-1][0], dp[i-1][1])
            }
        }

        // 마지막 집(N-1)을 어떤 색으로 칠했을 때든 가장 싼 값을 선택
        let answer = dp[N-1].min()!
        print(answer)
    }
}
