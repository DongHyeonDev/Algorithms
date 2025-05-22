//
//  2156.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 5/22/25.
//

//  문제 링크: https://www.acmicpc.net/problem/2156
//  알고리즘 분류: 다이나믹 프로그래밍

class BOJ2156: Solvable {
    // 메모리: 80248KB, 시간: 12ms, 코드 길이: 988B
    func run() {
        // 입력 처리
        let fileIO = RhynoFileIO()
        let n = fileIO.readInt()

        // 1-based 인덱싱을 위해 wines[0] = 0
        var wines = [0]
        for _ in 0..<n {
            let amount = fileIO.readInt()
            wines.append(amount)
        }

        // DP 배열 초기화
        // dp[i][0]: i번째 잔을 마시지 않은 상태의 최대량
        // dp[i][1]: i번째 잔을 마시고, 직전(i-1)잔은 마시지 않은 상태
        // dp[i][2]: i번째 잔을 마시고, 직전(i-1)잔도 마신(연속 2잔) 상태
        var dp = Array(repeating: [0, 0, 0], count: n + 1)

        // 초기 조건
        if n >= 1 {
            dp[1][0] = 0
            dp[1][1] = wines[1]
            dp[1][2] = 0
        }
        if n >= 2 {
            dp[2][0] = max(dp[1][0], dp[1][1], dp[1][2])
            dp[2][1] = max(dp[1][0], dp[1][2]) + wines[2]
            dp[2][2] = dp[1][1] + wines[2]
        }

        // DP 전이 (3잔부터)
        if n >= 3 {
            for i in 3...n {
                // i번째 잔을 건너뛰는 경우
                dp[i][0] = max(dp[i-1][0], dp[i-1][1], dp[i-1][2])
                // i번째만 마시고 직전 건너뛰기
                dp[i][1] = dp[i-1][0] + wines[i]
                // i-1, i 연속 마시되 i-2는 건너뛰기
                dp[i][2] = dp[i-1][1] + wines[i]
            }
        }

        // 결과 출력
        let answer = max(dp[n][0], dp[n][1], dp[n][2])
        print(answer)
    }
}
