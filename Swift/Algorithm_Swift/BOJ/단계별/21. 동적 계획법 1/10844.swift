//
//  10844.swift
//  Algorithm_Swift
//
//  Created by 김동현 on 5/21/25.
//

//  문제 링크: https://www.acmicpc.net/problem/10844
//  알고리즘 분류: 다이나믹 프로그래밍

class BOJ10844: Solvable {
    // 메모리: 79508KB, 시간: 8ms, 코드 길이: 1243B
    func run() {
        // 입력 받기
        guard let input = readLine(), let n = Int(input) else {
            fatalError("잘못된 입력입니다.")
        }
        
        // 모듈로 연산에 사용할 값
        let MOD = 1_000_000_000
        
        // dp[i][j]: 길이가 i이고 마지막 숫자가 j인 계단 수의 개수
        var dp = Array(repeating: Array(repeating: 0, count: 10), count: n + 1)
        
        // 길이가 1인 계단 수 초기화 (0으로 시작하는 수는 계단수가 아님)
        for i in 1...9 {
            dp[1][i] = 1
        }
        
        // 길이가 2 이상인 계단 수 계산
        if n >= 2 {
            for i in 2...n {
                for j in 0...9 {
                    // 마지막 숫자가 0인 경우, 이전 숫자는 반드시 1
                    if j == 0 {
                        dp[i][j] = dp[i-1][1] % MOD
                    }
                    // 마지막 숫자가 9인 경우, 이전 숫자는 반드시 8
                    else if j == 9 {
                        dp[i][j] = dp[i-1][8] % MOD
                    }
                    // 그 외의 경우, 이전 숫자는 j-1 또는 j+1
                    else {
                        dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % MOD
                    }
                }
            }
        }
        
        // 길이가 n인 모든 계단 수의 개수를 합하여 결과 출력
        var result = 0
        for j in 0...9 {
            result = (result + dp[n][j]) % MOD
        }
        
        print(result)
    }
}
