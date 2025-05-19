//
//  2579.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 5/19/25.
//

//  문제 링크: https://www.acmicpc.net/problem/2579
//  알고리즘 분류: 다이나믹 프로그래밍

import Foundation

class BOJ2579: Solvable {
    // 메모리: 79512KB, 시간: 16ms, 코드 길이: 1288B
    func run() {
        // 입력 처리
        guard let nString = readLine(),
              let n = Int(nString),
              n > 0 else {
            print("잘못된 입력입니다.")
            exit(0)
        }
        // 1-based 편의를 위해 scores[0]에 더미 0 삽입
        var scores = [0]
        for _ in 0..<n {
            guard let scoreString = readLine(),
                  let score = Int(scoreString) else {
                print("잘못된 입력입니다.")
                exit(0)
            }
            scores.append(score)
        }
        
        // dp 배열 초기화
        // dp[i][0]: i번째 계단을 밟되, 바로 전 계단(i-1)을 밟지 않은 경우
        // dp[i][1]: i번째 계단을 밟고, 바로 전 계단도 연속으로 밟은 경우
        var dp = Array(repeating: [0, 0], count: n + 1)
        
        // 첫 번째 계단
        dp[1][0] = scores[1]
        dp[1][1] = scores[1]
        
        // 두 번째 계단 (연속 두 칸 밟기 허용)
        if n >= 2 {
            dp[2][0] = scores[2]                // 바로 전 계단을 뛰어넘고 2만 밟음
            dp[2][1] = scores[1] + scores[2]    // 1→2 연속으로 밟음
        }
        
        // 3번째 계단부터 DP 전이
        if n >= 3 {
            for i in 3...n {
                // i번째만 밟고 i-1 뛰어넘기
                dp[i][0] = max(dp[i-2][0], dp[i-2][1]) + scores[i]
                // i-1→i 연속 두 칸
                dp[i][1] = dp[i-1][0] + scores[i]
            }
        }
        
        // 결과 출력
        // 마지막 계단은 반드시 밟아야 하므로 두 상태 중 큰 값을 선택
        let answer = max(dp[n][0], dp[n][1])
        print(answer)
    }
}
