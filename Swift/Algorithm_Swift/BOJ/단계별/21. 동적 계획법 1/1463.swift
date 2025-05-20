//
//  1463.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 5/20/25.
//

//  문제 링크: https://www.acmicpc.net/problem/1463
//  알고리즘 분류: 다이나믹 프로그래밍

import Foundation

class BOJ1463: Solvable {
    // 메모리: 87324KB, 시간: 48ms, 코드 길이: 273B
    func run() {
        // 입력 처리
        let N = Int(readLine()!)!
        // DP 배열 초기화
        var dp = [Int](repeating: 0, count: N + 1)
        
        // DP 전이
        for i in 2...N {
            // 1을 빼는 연산을 썼을 때
            dp[i] = dp[i - 1] + 1
            
            // 3으로 나눌 수 있으면 그 경우도 고려
            if i % 3 == 0 {
                dp[i] = min(dp[i], dp[i / 3] + 1)
            }
            // 2로 나눌 수 있으면 그 경우도 고려
            if i % 2 == 0 {
                dp[i] = min(dp[i], dp[i / 2] + 1)
            }
        }
        
        // 결과 출력
        print(dp[N])
    }
}
