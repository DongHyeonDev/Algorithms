//
//  1932.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 5/18/25.
//

//  문제 링크: https://www.acmicpc.net/problem/1932
//  알고리즘 분류: 다이나믹 프로그래밍

import Foundation

class BOJ1932: Solvable {
    // 메모리: 82004KB, 시간: 48ms, 코드 길이: 1362B
    func run() {
        // 안전하게 한 줄을 읽어서 Int로 변환
        guard let nLine = readLine(), let n = Int(nLine) else { exit(0) }
        
        // 삼각형 입력
        var triangle = [[Int]]()
        triangle.reserveCapacity(n)
        for _ in 0..<n {
            guard let parts = readLine()?.split(separator: " ").compactMap({ Int($0) }),
                  !parts.isEmpty
            else { exit(0) }
            triangle.append(parts)
        }
        
        // dp[i][j] 는 i번째 줄 j번째 칸까지 내려올 수 있는 최대 합
        var dp = [[Int]](repeating: [], count: n)
        for i in 0..<n {
            // i번째 줄에는 i+1개의 칸이 있으므로 0으로 초기화
            dp[i] = Array(repeating: 0, count: i + 1)
        }
        
        // 맨 꼭대기
        dp[0][0] = triangle[0][0]
        
        // 아래로 내려가면서 DP 계산
        for i in 1..<n {
            for j in 0...i {
                if j == 0 {
                    // 왼쪽 끝은 오직 바로 위에서만
                    dp[i][j] = dp[i-1][j] + triangle[i][j]
                } else if j == i {
                    // 오른쪽 끝은 오직 위 왼쪽 대각선에서만
                    dp[i][j] = dp[i-1][j-1] + triangle[i][j]
                } else {
                    // 중간 칸은 위 대각선 좌/우에서 내려올 수 있음
                    let leftUp = dp[i-1][j-1]
                    let up     = dp[i-1][j]
                    dp[i][j] = max(leftUp, up) + triangle[i][j]
                }
            }
        }
        
        // 마지막 줄에서 최대값
        let maxSum = dp[n-1].max() ?? 0
        print(maxSum)
    }
}
